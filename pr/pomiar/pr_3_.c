/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	Channel*  to_1WY;
	Channel*  from_1WE;
	Channel*  to_4WY;
	Channel*  from_4WE;
	int*      procNr;

	to_1WY     = (Channel *)  get_param (1);
	from_1WE   = (Channel *)  get_param (2);
	to_4WY     = (Channel *)  get_param (3);
	from_4WE   = (Channel *)  get_param (4);
	procNr     = (int *)      get_param (5);

	return 0;
}
