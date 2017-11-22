#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int add_to_list(linked_list *ll, char *s)
{
	if(ll==NULL)return -1;
	int index=ll->index;
	//printf("%d\n",index);
	ll->prev=NULL;
	linked_list* next_item=ll;
	while(next_item->next!=NULL)
	{
		next_item=next_item->next;
	}

	linked_list* new_item=(linked_list *)(malloc(sizeof(linked_list)));
	next_item->next=new_item;
	new_item->data=s;
	new_item->next=NULL;
	new_item->prev=next_item;
	index=next_item->index;
	printf("%d\n",index);
	index++;
	new_item->index=index;
	
	return index;	
}
int display_item(linked_list *ll)
{
	if(ll==NULL||ll->data==NULL)return -1;
	
	printf("index:%d ",ll->index);
	int i;
	printf(" %s ",ll->data);
	printf("prev:%x ",ll->prev);
	printf(" next:%x",ll->next);
	return 0;
}

int display_list(linked_list *ll)
{
		if(ll==NULL)return -1;

	linked_list* next_item=ll;
	int count=0;
	while(next_item->next!=NULL)	
	{
		display_item(next_item);
		printf("\n----------------------\n");	
		count++;
		next_item=next_item->next;
	}
		display_item(next_item);
		printf("\n----------------------\n");	


	

	return count;
		
}

linked_list * search_from_list(linked_list *ll, char *s)
{
	if(ll==NULL)return NULL;
	
	linked_list* next_item=ll;
	if(s==next_item->data)  return next_item;
	while(next_item->next!=NULL)
	{
		
		next_item=next_item->next;
		if(s==next_item->data) return next_item;
		
	}
	return NULL;
}

int delete_from_list(linked_list *ll, int index)
{	
	if(ll==NULL||index<=0)return -1;
	
	ll->index=0;
	if(index>count_items(ll)) return -1;
	linked_list* list_item=ll;
	linked_list* prev;
	int items_left;
	
	
	while(list_item!=NULL)
	{
		
		prev=list_item;
		list_item=list_item->next;
		if(index==list_item->index)break;
		
	}
	prev->next=list_item->next;
	items_left=count_items(ll);
	free(list_item);
	return items_left;
}

int count_items(linked_list *ll)
{
	if(ll==NULL)return -1;
	int count=0;
	linked_list* next_item=ll;
	while(next_item->next!=NULL)
	{
		next_item=next_item->next;
		count++;
	}

	return count;
}


void swap_items(linked_list *f, linked_list *s)
{

}
int linkedlist_status(linked_list *ll){
	return count_items(ll);
}

int empty_list(linked_list *ll){
	int i,j;
	j=count_items(ll);
	
	for(i=1;i<=j;i++)
	{
		delete_from_list(ll,i);
	}
	ll->next=NULL;
	ll->data=0;
	return 0;
}
