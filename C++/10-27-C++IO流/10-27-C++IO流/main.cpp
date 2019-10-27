#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct ServerInfo {
	char _ip[32];
	int _port;
};

struct ConfigManager {
public:
	ConfigManager(const char* configfile="bitserver.config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info) {
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info) {
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}
	void WriteTest(const ServerInfo& info) {
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadTest(ServerInfo& info) {
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile;
};
int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// 二进制读写
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// 文本读写
	cfgMgr.WriteTest(wtinfo);
	cfgMgr.ReadTest(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	/*ConfigManager con;
	ServerInfo s1, s2, s3;
	strcpy(s1._ip, "hehe");
	s1._port = 222333333;
	con.WriteBin(s1);
	con.ReadBin(s2);
	/*con.WriteTest(s1);
	con.ReadTest(s3);
	*/
	
	return 0;
}