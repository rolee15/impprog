#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int clear_stdin()
{
	int c;
	while ((c = getchar()) != '\n')
	{
	}
}

char *get_err_msg(int err_code)
{
	char *err_msg = "";
	switch (err_code)
	{
	case 1:
		err_msg = "Unexpected end of input... Try again!\n";
		break;

	case 2:
		err_msg = "Input contained multiple numbers... Try again!\n";
		break;

	case 3:
		err_msg = "Input was not a number... Try again!\n";
		break;

	default:
		err_msg = "Unknown error...Try again!\n";
		break;
	}

	return err_msg;
}

int read_number(int *n)
{
	int nitems;
	nitems = scanf("%d", n);

	int err_code = 0;
	if (nitems == EOF)
	{
		err_code = 1;
	}
	else if (nitems > 1)
	{
		err_code = 2;
	}
	else if (nitems == 0)
	{
		err_code = 3;
	}

	clear_stdin();

	return err_code;
}

int main()
{
	printf("Guessing Game\n\n");

	int lb, ub;
	int error;
	char *err_msg = "";

	do
	{
		printf("Lower bound: ");
		error = read_number(&lb);
		if (error)
		{
			err_msg = get_err_msg(error);
			printf(err_msg);
		}
	} while (error);

	do
	{
		printf("Upper bound: ");
		error = read_number(&ub);
		if (error)
		{
			err_msg = get_err_msg(error);
			printf(err_msg);
		}
	} while (error);

	if (ub < lb)
	{
		printf("You mixed up the upper and lower bounds, but it's OK, I can work with that...\n");
		int tmp = lb;
		lb = ub;
		ub = tmp;
		printf("New bounds: %d and %d\n", lb, ub);
	}

	if (lb == ub)
		printf("Not much of a challenge, but it's your game...\n");

	srand(time(NULL));
	int rnd_num = (rand() % (ub - lb + 1)) + lb;
	int guess;
	int count = 1;
	do
	{
		printf("Take a guess: ");
		error = read_number(&guess);
		if (error)
		{
			err_msg = get_err_msg(error);
			printf(err_msg);
			continue;
		}

		if (guess > ub || guess < lb)
		{
			printf("Did you forget the bounds you gave yourself?\n");
		}
		else if (guess < rnd_num)
		{
			printf("Guess higher!\n");
			count++;
		}
		else if (guess > rnd_num)
		{
			printf("Guess lower!\n");
			count++;
		}
		else if (guess == rnd_num)
		{
			printf("Congratz! You guessed right! You get a virtual cookie: 🍪\n");
			printf("You guessed right in %d guesses\n", count);
		}
	} while (guess != rnd_num);

	return 0;
}
