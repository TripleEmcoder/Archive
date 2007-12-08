/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	Channel*  to_2WY;
	Channel*  from_2WE;
	Channel*  to_3WY;
	Channel*  from_3WE;
	int*      procNr;

	to_2WY     = (Channel *)  get_param (1);
	from_2WE   = (Channel *)  get_param (2);
	to_3WY     = (Channel *)  get_param (3);
	from_3WE   = (Channel *)  get_param (4);
	procNr     = (int *)      get_param (5);

	return 0;
}
