#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"
ST_cardData_t cardData;
ST_terminalData_t termData;
extern ST_accountsDB_t DataBase[250];

extern ST_transaction_t TransactionDatabase[250];



void appStart(void)
{
	uint8 x, y, z, m;




	printf("Enter the card holder name\t");
	scanf_s("%s", cardData.cardHolderName, 25);
	getCardHolderName(&cardData);

	printf("Enter the card expiration date\t");
	scanf_s("%s", cardData.cardExpirationDate, 6);
	getCardExpiryDate(&cardData);

	printf("Enter the card primary acount number\t");
	scanf_s("%s", cardData.primaryAccountNumber, 20);
	getCardPAN(&cardData);

	printf("Enter the transaction date\t");
	scanf_s("%s", termData.transactionDate, 11);
	getTransactionDate(&termData);

	x = isCardExpired(&cardData, &termData);
	if (x == EXPIRED_CARD)
	{
		exit(0);
	}

	printf("Enter the max transaction amount\t");
	scanf("%f", &termData.maxTransAmount);
	setMaxAmount(&termData);

	printf("Enter the transaction amount\t");
	scanf("%f", &termData.transAmount);
	getTransactionAmount(&termData);

	y = isBelowMaxAmount(&termData);
	if (y == EXCEED_MAX_AMOUNT)
	{
		exit(0);
	}

	ST_transaction_t TransactionDatabase[250] =
	{
		{cardData,termData,APPROVED,1}
	};

	recieveTransactionData(TransactionDatabase);

	/*z = isValidAccount(&cardData);
	if (z == ACCOUNT_NOT_FOUND)
	{
		exit(0);
	}

	m = isAmountAvailable(&termData);
	if (m == LOW_BALANCE)
	{
		exit(0);
	}*/
}