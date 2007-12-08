/* --------------------------------------------------- *
 *   Szkielet pliku zrodlogo genrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	Channel*  to_4;
	Channel*  from_4;
	Channel*  to_1;
	Channel*  from_1;
	int*      procNr;
	int val;

	to_4     = (Channel *)  get_param (1);
	from_4   = (Channel *)  get_param (2);
	to_1     = (Channel *)  get_param (3);
	from_1   = (Channel *)  get_param (4);
	procNr     = (int *)      get_param (5);

	val = ChanInInt (from_2);

	while (val >= 0)   {
		ChanOutInt (to_master, val);

		val = ChanInInt (from_master);
	}

	return 0;
}
