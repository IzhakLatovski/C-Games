#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu(void);


void print_welcome_message()
{
	printf("HHHHH     HHHHH          AAAAAAA          NNNNNNN      NNNNN      GGGGGGGGG      MMMMM     MMMMM          AAAAAAA          NNNNNNN      NNNNN\n");
	printf("HHHHH     HHHHH         AAAA AAAA         NNNNNNNN     NNNNN     GGGG   GGGGG    MMMMMM   MMMMMM         AAAA AAAA         NNNNNNNN     NNNNN\n");
	printf("HHHHH     HHHHH        AAAA   AAAA        NNNNN NNN    NNNNN    GGGG             MMMM MM MM MMMM        AAAA   AAAA        NNNNN NNN    NNNNN\n");
	printf("HHHHHHHHHHHHHHH       AAAAAAAAAAAAA       NNNNN  NNN   NNNNN   GGGG     GGGGGG   MMMM  MMM  MMMM       AAAAAAAAAAAAA       NNNNN  NNN   NNNNN\n");
	printf("HHHHHHHHHHHHHHH      AAAAAAAAAAAAAAA      NNNNN   NNN  NNNNN   GGGG     GGGGGG   MMMM       MMMM      AAAAAAAAAAAAAAA      NNNNN   NNN  NNNNN\n");
	printf("HHHHH     HHHHH     AAAA         AAAA     NNNNN    NNN NNNNN    GGGG      GGGG   MMMM       MMMM     AAAA         AAAA     NNNNN    NNN NNNNN\n");
	printf("HHHHH     HHHHH    AAAA           AAAA    NNNNN     NNNNNNNN     GGGG    GGGG    MMMM       MMMM    AAAA           AAAA    NNNNN     NNNNNNNN\n");
	printf("HHHHH     HHHHH   AAAA             AAAA   NNNNN      NNNNNNN      GGGGGGGGGG     MMMM       MMMM   AAAA             AAAA   NNNNN      NNNNNNN\n");
	printf("\n© Izhak Latovski\n\n");

	sleep(2);
}


void print_rules()
{
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\nWelcome to the Hangman game!\n\n");
	printf("This is a 2 players game. Each player has to choose a word, between 5 and 10 letters, for his opponent.\n\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	menu();
}


void print_word(char* word, int* solved)
{
	unsigned int i=0;
	size_t length=strlen(word);

	for(i=0 ; i<length ; i++) {
		if(solved[i]) {
			printf("%c  ",toupper(word[i]));
		} else {
			printf("___  ");
		}
	}
	printf("\n\n");
}


void print_guessed_letters(int* letters)
{
	unsigned int i=0;

	printf("Guessed letters:\n");
	for(i=0 ; i<26 ; i++) {
		printf("%c ",'A'+i);		
	}
	printf("\n");
	for(i=0 ; i<26 ; i++) {
		if(letters[i]==0) {
			printf("  ");
		} else if(letters[i]==1) {
			printf("X ");
		} else if(letters[i]==2) {
			printf("√ ");
		}
	}
	printf("\n\n");
}


int check_win(char* word, int* solved)
{
	unsigned int i=0;

	for(i=0 ; i<strlen(word) ; i++) {
		if(solved[i]==0) {
			return 0;
		}
	}
	printf("WIN !!!!!!!!!!!!\n");
	return 1;
}


void print_man(int* lives)
{
	switch(*lives) {
		case 6:
			printf("   _____   (6/6)\n");
			printf("  |     |\n");
			printf("  |\n");
			printf("  |\n");
			printf("  |\n");
			printf("  |\n");
			printf("__|__\n\n");
			break;
		case 5:
			printf("   _____   (5/6)\n");
			printf("  |     |\n");
			printf("  |     O\n");
			printf("  |\n");
			printf("  |\n");
			printf("  |\n");
			printf("__|__\n\n");
			break;
		case 4:
			printf("   _____   (4/6)\n");
			printf("  |     |\n");
			printf("  |     O\n");
			printf("  |     |\n");
			printf("  |\n");
			printf("  |\n");
			printf("__|__\n\n");
			break;
		case 3:
			printf("   _____   (3/6)\n");
			printf("  |     |\n");
			printf("  |     O\n");
			printf("  |    /|\n");
			printf("  |\n");
			printf("  |\n");
			printf("__|__\n\n");
			break;
		case 2:
			printf("   _____   (2/6)\n");
			printf("  |     |\n");
			printf("  |     O\n");
			printf("  |    /|\\ \n");
			printf("  |\n");
			printf("  |\n");
			printf("__|__\n\n");
			break;
		case 1:
			printf("   _____   (1/6)\n");
			printf("  |     |\n");
			printf("  |     O\n");
			printf("  |    /|\\ \n");
			printf("  |    /\n");
			printf("  |\n");
			printf("__|__\n\n");
			break;
		case 0:
			printf("   _____   (0/6)\n");
			printf("  |     |\n");
			printf("  |     O\n");
			printf("  |    /|\\ \n");
			printf("  |    / \\ \n");
			printf("  |\n");
			printf("__|__\n\n");
			break;
	}
}


int make_move(char* word,int* solved,int* letters, int* lives)
{
	char letter;
	unsigned int i=0, found=0;

	printf("Pick your letter: \n");
	scanf("%s",&letter);
	for(i=0 ; i<26 ; i++) {
		if(letters[toupper(letter)-'A']>0)
		{
			printf("You already tried this letter, please try again\n");
			return 0;
		}
	}
	for(i=0 ; i<strlen(word) ; i++) {
		if(letter==word[i]) {
			solved[i]=1;
			letters[toupper(letter)-'A']=2;
			found=1;
		}
	}
	if(found==0) {
		letters[toupper(letter)-'A']=1;
		(*lives)--;
	}
	return 1;
}


void new_game()
{
	char player_choosing[16], player_guessing[16], word[16];
	int random_binary, lives=6, winner=0;
	int solved[16]={0}, letters[26]={0};

	srand(time(0));
	random_binary=rand()%2;

	printf("Hi. Please enter player 1 name:\n");
	if(random_binary==0) {
		scanf("%s",player_choosing);
		printf("Please enter player 2 name:\n");
		scanf("%s",player_guessing);
	} else {
		scanf("%s",player_guessing);
		printf("Please enter player 2 name:\n");
		scanf("%s",player_choosing);
	}	

	printf("\nRandomly chosen roles:\n");
	printf("%s is choosing a word.\n",player_choosing);
	printf("%s is guessing.\n",player_guessing);

	sleep(0);
	printf("\n%s, please enter your word (5-8 letter)\n",player_choosing);
	scanf("%s",word);

	printf("\n%s, now it's your turn to start guessing!\n\n",player_guessing);
	print_word(word,solved);

	while(winner==0 && lives>0) {
		while(1) {
			if(make_move(word,solved,letters,&lives)) {
				break;
			}
		}
		printf("\n-----------------------------------------------------------------------\n");
		print_word(word,solved);
		print_guessed_letters(letters);
		print_man(&lives);
		if(check_win(word,solved)) {
			winner=1;
		}
	}
	if(lives==0) {
		printf("GAME OVER !!!!!!!!!\nThe word was %s..",word);
	}

}


void menu()
{
	int chosen_menu_item=0;

	printf(".___________________________________.\n");
	printf("| Welcome! Please choose an option: |\n");
	printf("|                                   |\n");	
	printf("| 1. Start a new game (2 players)   |\n");
	printf("| 2. Rules                          |\n");
	printf("| 3. Exit                           |\n");
	printf("|___________________________________|\n");

	while(chosen_menu_item<1 || chosen_menu_item>1) {
		scanf("%d",&chosen_menu_item);
		if(chosen_menu_item<1 || chosen_menu_item>3) {
			printf("Wrong choose. Please choose an option, 1-3:\n");
			continue;
		}
		switch(chosen_menu_item) {
			case 1:
				new_game();
				break;
			case 2:
				print_rules();
				break;
			case 3:
				exit(0);
		}
	}
}


int main()
{
	print_welcome_message();
	menu();

	return 0;
}


/* TODO:
	  - check input string for length and type
	  - make the turns swap
	  - remember the score
	  - case sensitivity
	  */