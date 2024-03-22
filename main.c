#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 130

void encrypt_function(int _key, char _word[MAX_LENGTH]);
void decrypt_function(int _key, char _word[MAX_LENGTH]);
void bruteforce(char _word[MAX_LENGTH], int _keyMin, int _keyMax);


void bruteforce(char _word[MAX_LENGTH], int _keyMin, int _keyMax)
{
	for(int i=_keyMin; i<= _keyMax; i++)
	{
		printf("key:%d :",i);
		decrypt_function(i, _word);
		
	}

}




void decrypt_function(int _key, char _word[MAX_LENGTH])
{
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	for (int i = 0; i<strlen(_word); i++)
	{
		if(_word[i] == ' ')
		{
			printf(" ");
		}	
		if(_word[i] == '\'')
		{
			printf("'");
		}			
		for (int j = 0; j<=strlen(alphabet); j++)
		{
			int nb = j-_key;
			while(nb < 0 || nb >= 26)
			{
				if(nb<0)
				{
					nb+=26;
				} else if (nb>=26)
				{
					nb-=26;
				}
			}
			if (_word[i] == alphabet[j])
			{
				printf("%c", alphabet[nb]);
			}
		}
			
	} 
	printf("\n");	
}


void encrypt_function(int _key, char _word[MAX_LENGTH])
{
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	for (int i = 0; i<strlen(_word); i++)
	{
		if(_word[i] == ' ')
		{
			printf(" ");
		}			
		for (int j = 0; j<=strlen(alphabet); j++)
		{
			int nb=j+_key;
			while(nb < 0 || nb >= 26)
			{
				if(nb<0)
				{
					nb+=26;
				} else if (nb>=26)
				{
					nb-=26;
				}
			}
			if (_word[i] == alphabet[j])
			{
				printf("%c", alphabet[nb]);
			}

		}
			
	} 
	printf("\n");	
}



int main(void)
{
	int user_choice, key, keyMin, keyMax;
	char word[MAX_LENGTH];
	printf("Encrytp or Decrypt or BruteForce ? (1/2/3):");
	scanf("%d",&user_choice);


	switch (user_choice) 
	{
		case 1:
			printf("Encrypt\n");
			printf("Word to encrypt :");
			getchar();	
			fgets(word, MAX_LENGTH, stdin);
			printf("Enter the key :");
			scanf("%d", &key);
			encrypt_function(key, word);
			break;
		case 2:
			printf("Decrypt\n");	
			printf("Word to decrypt :");
			getchar();	
			fgets(word, MAX_LENGTH, stdin);	
			printf("Enter the key :");
			scanf("%d", &key);
			decrypt_function(key, word);
			break;
		case 3:
			printf("Word to decrypt :");
			getchar();	
			fgets(word, MAX_LENGTH, stdin);	
			printf("Please enter a keyMin :");
			scanf("%d", &keyMin);
			printf("Please enter a keyMax :");
			scanf("%d", &keyMax);
			printf("Bruteforce en cours :\n");
			bruteforce(word,keyMin,keyMax);
			break;
		default :
			while (user_choice != 1 && user_choice != 2)
			{
				printf("not the right value, try again :");
				scanf("%d",&user_choice);
			}
			if (user_choice == 1)
			{
				printf("Encrypt\n");
			}else if (user_choice == 2)
			{
				printf("Decrypt\n");
			}
	}
	return 0;
}


