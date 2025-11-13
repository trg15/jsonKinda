#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
typedef struct StoreList{
	int noOfItem;
	char *text;
	struct StoreList *next;
}StoreList;

/*
 * Format for the charList
 * {"<integer_no_of_item>":"text"<, if going to continue>}
 */
StoreList *giveTextInList(char *charList){
	StoreList *listHead = NULL;StoreList *tempList = NULL;
	char *temp1 = NULL;char *temp4 = NULL;char *temp3 = NULL;char *temp2 = NULL;
	char *tempString = charList;
	char *tempKey = NULL;char *tempValue = NULL;
	int sizeOfKey = 0;int sizeOfValue = 0;
	temp1 = strchr(tempString, '{');
	if(temp1 == NULL){
		return NULL;
	}
	temp1 = NULL;
	tempString += 1;
	while(true){
		temp1 = NULL;temp4 = NULL;temp3 = NULL;temp2 = NULL;
		if(tempKey != NULL){
			free(tempKey);
		}
		if(tempValue != NULL){
			free(tempValue);
		}
		temp1 = strchr(tempString, '\"'); //finding the first double quotes
		if(temp1 == NULL){
			break;
		}
		temp1 += 1;
		puts(temp1);
		temp2 = strchr(temp1, '\"');//finding the end double quote of the key value
		if(temp2 == NULL){
			break;
		}
		temp3 = strstr(temp2, ":\"");//finding the colon and initial double quote of the value string
		if(temp3 == NULL){
			break;
		}
		temp3 += 2;
		temp4 = strchr(temp3, '\"');//finding the end double quote of the value string
		if(temp4 == NULL){
			break;
		}
		sizeOfKey = (temp2 - temp1);//calculating the length of the key string
		sizeOfValue = (temp4 - temp3);//calculating the length of the value string
		tempKey = (char *) malloc(sizeOfKey + 1);
		tempValue = (char *) malloc(sizeOfValue + 1);
		memset(tempKey, 0, sizeOfKey+1);
		memset(tempValue, 0, sizeOfValue+1);
		memcpy(tempKey, temp1, sizeOfKey);
		memcpy(tempValue, temp3, sizeOfValue);
		puts(tempKey);
		puts(tempValue);
		StoreList *newNode = (StoreList *) malloc(sizeof(StoreList));
		memset(newNode, 0, sizeof(StoreList));
		newNode->noOfItem = atoi(tempKey);
		newNode->text = (char *) malloc(sizeOfValue * sizeof(char));
		memset(newNode->text, 0, sizeOfValue);
		memcpy(newNode->text, tempValue, sizeOfValue);
		newNode->next = NULL;
		if(listHead == NULL){
			listHead = newNode;
			tempList = listHead;
		}
		else{
			tempList = tempList->next;	
			tempList = newNode;
		}
		temp1 = NULL;
		temp1 = strchr(temp4, ',');
		if(temp1 == NULL){
			break;
		}
		tempString = temp1;
	}
	return listHead;
}

int addTextToTheListFromTheHead(char *text){
}


int main(){
	char *string = "{\"1\":\"rajagopalan\",\"2\":\"anand\"}";
	giveTextInList(string);
	return 0;
}
