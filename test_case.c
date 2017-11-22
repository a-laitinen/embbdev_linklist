#include <gtest/gtest.h>
#include "linkedlist.h"



TEST(addtest,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list head;

    head.next=0;
	head.prev=0;
    head.data=str;
    head.index=0;


    i=add_to_list(&head,str1);
    EXPECT_EQ(1,i);

    i=add_to_list(&head,str2);
    EXPECT_EQ(2,i);

    i=add_to_list(&head,str3);
    EXPECT_EQ(3,i);

    i=add_to_list(&head,str4);
    EXPECT_EQ(4,i);

    i=add_to_list(&head,str5);
    EXPECT_EQ(5,i);

    i=add_to_list(&head,str6);
    EXPECT_EQ(6,i);

}

TEST(statustest,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list head;

    head.next=0;
	head.prev=0;
    head.data=str;
    head.index=0;


    i=add_to_list(&head,str1);
	i=linkedlist_status(&head);
    EXPECT_EQ(1,i);

    add_to_list(&head,str2);
  	i=linkedlist_status(&head);
    EXPECT_EQ(2,i);

    add_to_list(&head,str3);
	i=linkedlist_status(&head);
    EXPECT_EQ(3,i);

    add_to_list(&head,str4);
	i=linkedlist_status(&head);
    EXPECT_EQ(4,i);

    add_to_list(&head,str5);
	i=linkedlist_status(&head);
    EXPECT_EQ(5,i);

    add_to_list(&head,str6);
	i=linkedlist_status(&head);
    EXPECT_EQ(6,i);

}


TEST(display_item,add_to_list)
{
    int result;
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *find;
    linked_list head;
    head.next=0;
	head.prev=0;
    head.data=str;
    head.index=0;

    i=add_to_list(&head,str1);
    i=add_to_list(&head,str2);
    i=add_to_list(&head,str3);
    i=add_to_list(&head,str4);
    i=add_to_list(&head,str5);
    i=add_to_list(&head,str6);

    find=head.next;
    display_item(find);

    find=head.next;
    display_item(find);

    find=head.next;
    display_item(find);

    find=head.next;
    display_item(find);

    find=head.next;
    display_item(find);


}

TEST(display_list,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list head;
    head.next=0;
	head.prev=0;
    head.data=str;
    head.index=0;

    i=add_to_list(&head,str1);
    i=add_to_list(&head,str2);
    i=add_to_list(&head,str3);
    i=add_to_list(&head,str4);
    i=add_to_list(&head,str5);
    i=add_to_list(&head,str6);


    display_list(&head);
}


TEST(delete,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list head;
    head.next=0;
	head.prev=0;
    head.data=str;
    head.index=0;

    i=add_to_list(&head,str1);
    i=add_to_list(&head,str2);
    i=add_to_list(&head,str3);
    i=add_to_list(&head,str4);
    i=add_to_list(&head,str5);
    i=add_to_list(&head,str6);
	EXPECT_EQ(i,6);

    i=delete_from_list(&head,2);
	EXPECT_EQ(i,5);

    i=delete_from_list(&head,5);
	EXPECT_EQ(i,4);

    i=delete_from_list(&head,4);
	EXPECT_EQ(i,3);

    i=delete_from_list(&head,1);
	EXPECT_EQ(i,2);

}


TEST(delete,multi) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list head;
    head.next=0;
	head.prev=0;
    head.data=str;
    head.index=0;

    i=add_to_list(&head,str1);
    i=add_to_list(&head,str2);
    i=add_to_list(&head,str3);
    i=add_to_list(&head,str4);
    i=add_to_list(&head,str5);
    i=add_to_list(&head,str6);

    for(i=0; i<40; i++)
        add_to_list(&head,str1);


    i=delete_from_list(&head,12);
    EXPECT_EQ(i,45);
    i=delete_from_list(&head,22); /*test case was missing 'i=' in front of every delete_from_list function call */
    EXPECT_EQ(i,44);
    i=delete_from_list(&head,25);
    EXPECT_EQ(i,43);
    i=delete_from_list(&head,32);
    EXPECT_EQ(i,42);
    i=delete_from_list(&head,38);
    EXPECT_EQ(i,41);

    i=delete_from_list(&head,380);
    EXPECT_EQ(i,-1);

}

TEST(empty,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list head;
    head.next=0;
	head.prev=0;
    head.data=str;
    head.index=0;

    i=add_to_list(&head,str1);
    i=add_to_list(&head,str2);
    i=add_to_list(&head,str3);
    i=add_to_list(&head,str4);
    i=add_to_list(&head,str5);
    i=add_to_list(&head,str6);
    empty_list(&head);
	
}
TEST(prev_pointer,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
	linked_list* tmp;

    linked_list head;
    head.next=0;
	head.prev=0;
    head.data=str;
    head.index=0;
	
	i=add_to_list(&head,str1);
    i=add_to_list(&head,str2);
    i=add_to_list(&head,str3);
    i=add_to_list(&head,str4);
    i=add_to_list(&head,str5);
    i=add_to_list(&head,str6);
	
	
	tmp=&head;
	EXPECT_EQ(&head,tmp->next->prev);
	EXPECT_EQ(tmp->next,tmp->next->next->prev);
	EXPECT_EQ(tmp->next->next->next,tmp->next->next->next->next->prev);


	
}
TEST(prev_pointer,delete) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
	linked_list* tmp;

    linked_list head;
    head.next=0;
	head.prev=0;
    head.data=str;
    head.index=0;
	
	i=add_to_list(&head,str1);
    i=add_to_list(&head,str2);
    i=add_to_list(&head,str3);
    i=add_to_list(&head,str4);
    i=add_to_list(&head,str5);
    i=add_to_list(&head,str6);
	
	
	tmp=&head;
	EXPECT_EQ(tmp->next->next->prev,tmp->next);
	ASSERT_STREQ(tmp->next->data,(char*)"zero");
	delete_from_list(&head,1);
	ASSERT_STREQ(tmp->next->data,(char*)"first");
	EXPECT_EQ(tmp->next->next->prev,tmp->next);



	
}



