#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;
void insert_from_end(){
	struct node *ptr,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data you want to insert:\n");
	scanf("%d",&temp->data);
	printf("You inserted:%d\n",temp->data);
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
	ptr=head;
	while(ptr->next != NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
}
}
void display(){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
		if(head==NULL){
		printf("Empty linklist.");
	}
	ptr=head;
	while(ptr !=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
void del_from_end(){
	if(head==NULL){
		printf("Blank linked list.");
	}
	else if(head->next==NULL){
		free(head);
		head=NULL;
	}
	else{
		struct node *temp, *ptr;
		ptr=head;
		while(ptr->next !=NULL){
			temp=ptr;
			ptr=ptr->next;
		}
		free(ptr);
		ptr=NULL;
		temp->next=NULL;
	}
}
void insert_from_begining(){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter data you wanna add:\n");
	scanf("%d",&ptr->data);
	printf("You inserted:%d\n",ptr->data);
	ptr->next=NULL;
	ptr->next=head;
	head=ptr;
//	while(ptr->next !=NULL){
//			ptr=ptr->next;
//		}
	
}
void insert_At_certain_position(){
	struct node *temp,*ptr;
	int pos;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data to insert:\n");
	scanf("%d",&temp->data);
	printf("You inserted:%d\n",temp->data);
	printf("Position where you want to insert:");
	scanf("%d",&pos);
	pos--;
	ptr=head;
	while(pos!=1){
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	ptr->next=temp;
	
}
void del_from_begining(){
	struct node *ptr;
	ptr=head;
	head=ptr->next;
	free(ptr);
	ptr=NULL;
}
del_from_A_certain_position(){
	if(head==NULL){
		printf("Empty linked list");
	}
	else if(head->next==NULL){
		free(head);
		head=NULL;
	}
	else{
		int position;
		struct node *ptr=head;
		struct node *temp=head;
		printf("Enter position you want to delete:");
		scanf("%d",&position);
		while(position!=1){
			temp=ptr;
			ptr=ptr->next;
			position--;
		}
		temp->next=ptr->next;
		free(ptr);
		ptr=NULL;
	}
}


int main(){
	int n;
	while(1){
		printf("\n1.Insert from end:\n");
		printf("\n2.Insert at certain position:\n");
		printf("\n3.Insert from front:\n");
		printf("\n4.Dislay:\n");
		printf("\n5.Delete\n");
		printf("\n6.Delete from begining\n");
		printf("\n7.del from A certain position\n");
		printf("\nChoose option:\n");
		scanf("%d",&n);
		switch(n){
		
		case 1:insert_from_end();
		break;
		case 2:insert_At_certain_position();
		break;
		case 3:insert_from_begining();
		break;
		case 4:display();
		break;
		case 5:del_from_end();
		break;
		case 6:del_from_begining();
		break;
		case 7:del_from_A_certain_position();
		break;
}
}
}

