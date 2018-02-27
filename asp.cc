//编译器暂不支持filesystem
#include <filesystem>
#include <wregex>
#include <wstring>

using namespace std;
namespace fs=std::filesystem;

int main()
{
	fs::path p=fs::current_path();
	wstring ws{"(.*)(\\.asp)$"};
	wregex wr{ws};
	wstring fmt{"$1.torrent"};
	wstring dest;

	for(auto& pn:fs::directory_iterator(p))
	{
		wregex_replace(dest,pn.wstring(),fmt);
		fs::rename(p/pn,p/dest);
	}
	return 0;
}
