#include <libgadu.h>

namespace InstantMessaging
{
	namespace Protocols
	{
		namespace GG
		{
			public ref class GGSession
			{
			private:
				gg_session* session;
			public:
				GGSession();
				~GGSession();
				void send(System::String^ text);
			};
		}
	}
}