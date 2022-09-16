/*
 * card.c
 *
 * Created on: Aug 16, 2022
 * Author: Mostafa Eltony
 */
#include "card.h"
#include <stdio.h>    //for printf function test
#include <string.h>  //for strlen function

 /*this function take a string that contain card name
 and make sum operations on it to cheak if the name is correct or not*/
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{

	/*we cheack if the length of name string is less than 20 element or greater than 24 or did not have any elements
	that will be a wrong name but if the length other wise or is in the scope of 20 to 24 that will be true name  */
	if (strlen(cardData->cardHolderName) < 20 || strlen(cardData->cardHolderName) > 24 || strlen(cardData->cardHolderName) == 0)
	{

		printf("wrong name\n");//to test that function is working and the name is wrong
		return WRONG_NAME;
	}
	else
	{
		printf("true name\n");//to test that function is working and the name is true
		return CARD_OK;
	}
}

/*this function take a string that contain card expiration date that contain from 2 integers is the format of month
and "/" operator and another 2 integers is the year
and make sum operations on it to cheak if the name is correct or not*/
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	/*we cheack if the length of expiration string is equal to 5 elements and third element is
	'/' operator that will be a true expiration date formate other wise is wrong formate */
	if (strlen(cardData->cardExpirationDate) == 5 && cardData->cardExpirationDate[2] == '/')
	{
		printf("true expired date format\n");//to test that function is working and the expiration date is true
		return CARD_OK;

	}
	else
	{
		printf("wrong expired date format\n");//to test that function is working and the expiration date is wrong
		return WRONG_EXP_DATE;
	}
}

/*this function take a string that contain primary account number and cheak if its formatevis true or not*/
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	/*we cheak if the length of string is less than 16 element or more than 19 element or did not have any elements
	that will be a wrong formate else will be true formate*/
	if (strlen(cardData->primaryAccountNumber) < 16 || strlen(cardData->primaryAccountNumber) > 19 || strlen(cardData->primaryAccountNumber) == 0)
	{
		printf("wrong PAN\n");//to test that function is working and the PAN is wrong
		return WRONG_PAN;
	}
	else
	{
		printf("true PAN\n");//to test that function is working and the PAN is true
		return CARD_OK;
	}
}
