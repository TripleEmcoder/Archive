#include <libgadu.h>

namespace DotTalk
{
		namespace GG
		{
			public ref class GGSession
			{
			private:
				gg_session* session;
			public:
				GGSession(int login, System::String^ password);
				~GGSession();
				void send(int login, System::String^ text);
			};
		}
}