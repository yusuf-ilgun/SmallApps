/* There are 'n' number of boxes. One of them has the reward.
 * Other boxes are empty. You choose one box.
 * 'n-2' boxes are revealed, only your box and one of the other boxes stay closed.
 * So it is asked for you to swap your box with the last one that is closed.
 * This program calculates odds for if you swap your boxes every time, or never swap your box.
 *
 * Since odd of your first pick to be correct gets lower while the box number increases,
 * swapping is always correct choice statistically ( unless there are 2 boxes, which makes odds 50-50 )
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int choice;
int r;

int box_number = 0;
int win_count = 0;
int total_count = 0;
int game_count = 0;
int swapEnabled = 0;

int main()
{
	srand(time(NULL));
	
	printf("Enter number of boxes: ");
	scanf("%d",&box_number);
	printf("Enter number of games: ");
	scanf("%d",&game_count);
	printf("\n");
	printf("Swap your boxes? (1:Enabled, 0:Disabled)");
	scanf("%d",&swapEnabled);

	for(int i=0; i<game_count; i++) {
		// get random winning box
		r = rand()%box_number;
		
		// player's choice of box number
		choice = rand()%box_number;

		if(swapEnabled) {
			// accounts that players always swap their boxes ( so if their pick is not the correct one, when they swap they win )
			if(choice != r) {
				win_count++;
			}
		} else {
			// player never swaps their boxes ( so if their first pick is the correct one, they win )
			if(choice == r)
				win_count++;
		}

		total_count++;
		printf("\e[1;1H\e[2J");
		printf("random => %d\n",r);
		printf("choice => %d\n",choice);
		printf("\nwin_count => %d\n",win_count);
		printf("tot_count => %d\n",total_count);
	}

	printf("_________________\n");
	printf("win_rate  => %f\n",(float)win_count/(float)total_count);

	if(swapEnabled)
		printf("Swapping everytime!\n");
	else
		printf("Staying everytime!\n");

}
