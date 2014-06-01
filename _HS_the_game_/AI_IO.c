#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "AI_IO.h"


void make_deck()
{
	FILE *fp;
	fp = fopen("cards.csv", "w");
	
	char names[255][30] = {"Dido", "Lubo", "Nike", "Nartziz", "Nina_Dobrev", "Samorai_Jack", "Zed", "Faker", "Tisho", "Gavrata", "Batman", "Joker",
		 "Kravara", "Kirta", "Sapuna", "Smyrtniq", "Mishoka", "Sverlosiniq", "Blizalkata", "Swetkawitzata", "Off", "Blediq", "Rijiq", "Ice-cream", 
		 "Alo_Alo", "Cvetno_ponny", "Pleshivoto", "Kukata", "Krivaka", "Zelkata"};
		 
	srand(time(NULL));
	int i;
	for(i=0; i<30; i++)
	{
		int power;
		int life;
		int mana_cost;
		power = rand()%10+1;
		life = rand()%(10-power+1)+1;
		mana_cost = rand()%(((life+power)/2)+1)+1;
		
		fprintf(fp,"%s,%d,%d,%d\n", names[i], power, life, mana_cost);
	}
	
	fclose(fp);
}

void read_card_s_names_deck()
{
	FILE *fp;
	fp = fopen("cards.csv", "r");
	char buffer[255];
	int i;
	for(i=0; i<30; ++i) 
	{
		fscanf(fp, "%s", buffer);
		char *token = strtok(buffer, ",");
		printf("%s\n", token);
	}
	fclose(fp);
}


int main()
{
	make_deck();
	read_card_s_names_deck();
	
	return 0;
}








