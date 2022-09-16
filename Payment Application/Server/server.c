/*
 * server.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Mostafa
*/

#include "server.h"
#include <stdio.h>
#include <string.h>
ST_accountsDB_t DataBase[250] =
{
	{2000.00,"3010801240931112574"},
	{6000.00,"2345678910111211589"},
	{3250.25,"6228710870023450848"},
	{1500.12,"4567891011121231412"},
	{500.00 ,"2586491735487857785"},
	{2100.00,"6548215263371947210"},
	{0.00   ,"9713612345248547635"},
	{1.00   ,"7931235414862525857"},
	{10.12  ,"1238596712345685489"},
	{0.55   ,"4565748978932196854"},
};

uint8 index;
EN_transStat_t recieveTransactionData(ST_transaction_t* transData)
{
	if (isValidAccount(&transData->cardHolderData) == ACCOUNT_NOT_FOUND)
	{
		transData->transState = DECLINED_STOLEN_CARD;
		//if (saveTransaction(transData) == SAVING_FAILED)return INTERNAL_SERVER_ERROR;
		return DECLINED_STOLEN_CARD;
	}
	if (isAmountAvailable(&transData->terminalData) == LOW_BALANCE)
	{
		transData->transState = DECLINED_INSUFFECIENT_FUND;
		//if(saveTransaction(transData) == SAVING_FAILED)return INTERNAL_SERVER_ERROR;
		return DECLINED_INSUFFECIENT_FUND;
	}
	transData->transState = APPROVED;
	DataBase[index].balance -= transData->terminalData.transAmount;
	printf("New balance is %f\n", DataBase[index].balance);
	/*if (saveTransaction(transData) == SAVING_FAILED)
	{
		return INTERNAL_SERVER_ERROR;
	}*/
	return APPROVED;
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{

	uint8 found = 0, exist = 1;
	for (uint8 i = 0; i < 255; i++)
	{
		exist = 1;
		for (uint8 j = 0; j < 20; j++)
		{
			if (DataBase[i].primaryAccountNumber[j] != cardData->primaryAccountNumber[j])
			{
				exist = 0;
				break;
			}
		}
		if (exist)
		{
			found = 1;
			index = i;
			break;
		}
	}
	if (!found)
	{
		printf("Account is not Exist  DECLINED_STOLEN_CARD\n");
		return ACCOUNT_NOT_FOUND;

	}
	else
	{
		printf("Account is Exist\n");
		return SERVER_OK;
	}




}


EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	if (termData->transAmount > DataBase[index].balance)
	{
		printf("low balance \n");
		return LOW_BALANCE;
	}
	else
	{
		printf("balance is exist\n");
		return SERVER_OK;
	}

}
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{

	transData->transactionSequenceNumber++;

}
EN_serverError_t getTransaction(uint32 transactionSequenceNumber, ST_transaction_t* transData)
{
	return APPROVED;
}
