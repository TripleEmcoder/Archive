/* --------------------------------------------------- *
 *   Szkielet pliku zrodlogo genrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <stdio.h>
#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	Channel*  to_2;
	Channel*  from_2;
	Channel*  to_3;
	Channel*  from_3;
	int*      procNr;
	int i;

	to_2     = (Channel *)  get_param (1);
	from_2   = (Channel *)  get_param (2);
	to_3     = (Channel *)  get_param (3);
	from_3   = (Channel *)  get_param (4);
	procNr     = (int *)      get_param (5);

	for (i = 1; i < 5; ++i)   
	{
		int	val;

		printf ("Proc: %d: Sending %d\n", *procNr, i);
		ChanOutInt (to_2, i);

		val = ChanInInt(from_2);
		printf ("Proc: %d: Received %d\n", *procNr, val);
	}

	ChanOutInt(to_2, -1);  

	exit_terminate(0);

	return 0;
}
