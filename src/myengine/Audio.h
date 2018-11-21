#pragma comment(lib,"openal32.lib")

#include <memory>
#include <string>

namespace myengine
{
struct AudioCreate;

	class Audio
	{
		std::shared_ptr<AudioCreate> create;
	public:
		Audio();
		Audio(std::string path);
		void load(std::string path);
		void play(float volume, float varMin, float varMax);
		void play();
		
	};
}
