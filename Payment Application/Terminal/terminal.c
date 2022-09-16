/*
 * terminal.c
 *
 * Created on: Aug 16, 2022
 * Author: Mostafa Eltony
 */
#include "terminal.h"
#include <stdio.h> //this for printf function
#include <string.h>//for strlen function

 /*this function takes a string that have the day of operation <transaction date> and cheak about his formate
 the string consists of 2 integers <day> and '/' operator , 2 integers <month> and '/' operator
 and 2 integers <year> this is the true formate*/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	/*we cheak if the length of transaction date is less than 10 elements or third and 5th element non equal '/'
	or string is empty that will be a wrong formate   */
	if (strlen(termData->transactionDate) < 10 || termData->transactionDate[2] != '/' || strlen(termData->transactionDate) == 0 || termData->transactionDate[5] != '/')
	{
		printf("wrong date format\n");//to test that function is working and the transaction date is wrong formate
		return WRONG_DATE;
	}
	else
	{
		printf("true date format\n");//to test that function is working and the transaction date is true formate
		return TERM_OK;
	}
}

/*this function takes 2 elements card expired date and transaction date and compare between them and cheak if card expired or not*/
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{/* we cheak first about the year if the year of card expired date is grater than or equal transaction date if it is greater then card not expired*/
	if (cardData->cardExpirationDate[4] >= termData->transactionDate[9] && cardData->cardExpirationDate[3] >= termData->transactionDate[8])
	{
		//we cheak if the years are equal we will compare the months
		if (cardData->cardExpirationDate[4] == termData->transactionDate[9] && cardData->cardExpirationDate[3] == termData->transactionDate[8])
		{
			//if the number of tens on card expiration is greater than tens in transaction that will be true
			if (cardData->cardExpirationDate[0] > termData->transactionDate[3])
			{
				printf("card is not expired\n");
				return TERM_OK;
			}
			/*if the number of tens on card expiration is equal to tens in transaction = 0 we will cheak the single element
			if the single element of card expiration date greater than single element of transaction date that will be true*/
			else if (cardData->cardExpirationDate[1] > termData->transactionDate[4] && termData->transactionDate[3] == 0)
			{
				printf("card is not expired\n");//to test that function is working and the card is not expired
				return TERM_OK;
			}
			else
			{
				printf("card is expired\n");//to test that function is working and the card is expired
				return EXPIRED_CARD;
			}
		}
		printf("card is not expired\n");//to test that function is working and the card is not expired
		return TERM_OK;
	}
	printf("card is expired\n");//to test that function is working and the card is not expired
	return EXPIRED_CARD;
}

//this function takes the amount value and cheak if it true value or not
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	//if trans amount is negative number or equal 0 that will be wrong
	if (termData->transAmount <= 0)
	{
		printf("invalid amount\n");//to test that function is working and the amount is invalid
		return INVALID_AMOUNT;
	}
	//if it is positive number that will be true
	else
	{
		printf("valid amount\n");//to test that function is working and the amount is valid
		return TERM_OK;
	}

}

//this function takes the max amount value and cheak if it true value or not
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	//if max trans amount is negative number or equal 0 that will be wrong
	if (termData->maxTransAmount <= 0)
	{
		printf("invalid max amount\n");//to test that function is working and the max amount is invalid
		return INVALID_MAX_AMOUNT;
	}
	//if it is positive number that will be true
	else
	{
		printf("valid max amount\n");//to test that function is working and the max amount is valid
		return TERM_OK;
	}
}
/*this function compare between trans amountand max trans amount if the amount is greater than the max amount that wrong
and max amount need to exceed*/
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		printf("Exceed max amount\n");//to test that function is working and the max amount need to exceed
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		printf("valid amount range\n");//to test that function is working and the max amount is valid
		return TERM_OK;
	}
}