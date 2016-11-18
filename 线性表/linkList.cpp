#include<stdio.h>
#include<stdlib.h>
typedef struct List {
	char ch;
	struct List * next;
} List;
void show(List *str){
    str = str->next;
	while(str!=NULL){
		printf("%c",str->ch);
		str = str->next;
	}
}
List *deleteDuplicates(List *str){
	List *result = (List*)malloc(sizeof(List));
	result->next = NULL;
	List *presult = result->next;
	List *temp1 = str->next;
	int flag = 0;
	while(temp1!=NULL){
		flag = 0;
		presult = result->next;
		if(presult==NULL){
			List *pnew = (List*)malloc(sizeof(List));
			pnew->ch = temp1->ch;
			pnew->next = result->next;
			result->next = pnew;
			temp1 = temp1->next;
			continue;
		}
		while(presult!=NULL){
			//printf("lalalala\n");
			if(presult->ch == temp1->ch){
				flag = 0;
				break;
			}
			flag = 1;
			presult = presult->next;
		}
		if(flag){
			//printf("add\n");
			List *pnew = (List*)malloc(sizeof(List));
			pnew->ch = temp1->ch;
			pnew->next = result->next;
			result->next = pnew;
		}
		temp1 = temp1->next;
	}
    return result;
}
List *Union(List*str1,List*str2){
    //str1 = deleteDuplicates(str1);
	List *result = (List*)malloc(sizeof(List));
	result->next = NULL;
	List *temp1,*temp2;
	temp1=str1->next;
	temp2=str2->next;
	while(temp1!=NULL){
		List *pnew = (List*)malloc(sizeof(List));
		pnew->ch = temp1->ch;
		pnew->next = result->next;
		result->next = pnew;
		temp1 = temp1->next;
	}
	temp1=str1->next;
	temp2=str2->next;
	int flag;
	while(temp2!=NULL){
		flag = 0;
		temp1 = str1->next;
		while(temp1!=NULL){
			if(temp2->ch == temp1->ch){
				flag = 0;
				break;
			}
            flag = 1;
			temp1 = temp1->next;
		}
		if(flag){
			List *temp3 = (List*)malloc(sizeof(List));
            temp3->ch = temp2->ch;
            temp3->next = result->next;
            result->next = temp3;
		}
		temp2 = temp2->next;
	}
	return result;
}
List *intersection(List*str1,List*str2){
	List *result = (List*)malloc(sizeof(List));
	result->next = NULL;
	List *temp1 = str1->next;
	List *temp2 = str2->next;
	while(temp2!=NULL){
		temp1 = str1->next;
		while(temp1!=NULL){
			if(temp1->ch == temp2->ch){
				List *pnew = (List*)malloc(sizeof(List));
				pnew->ch = temp2->ch;
				pnew->next = result->next;
				result->next = pnew;
			}
			temp1 = temp1->next;
		}
		
		temp2 = temp2->next;
	}
	return result;
}
List *create(){
	List *p = (List*)malloc(sizeof(List));
	List *head = p;
	p->next = NULL;
	printf("enter a string\n");
	while(true){
		char c = getchar();
		if(c>='a'&&c<='z'){
			List *pnew = (List*)malloc(sizeof(List));
			pnew->ch = c;
			pnew->next = NULL;
			p->next = pnew;
			p = p->next;
			continue;
		} else if(c=='\n'){
			break;
		} else {
			printf("\n输入字母只能是a-z的小写字母\n");
			return NULL;
		}
	}
	return head;
}
int main(){
	List *str1 = create();
	List *str2 = create();
	if(str1==NULL||str2==NULL){
		printf("输入有误\n");
		system("pause");
		return 1;
	}
	str1 = deleteDuplicates(str1);
	str2 = deleteDuplicates(str2);
	List *unionResult = Union(str1,str2);
    printf("Set1USet2=\n");
	show(unionResult);
	List *intersectionResult = intersection(str1,str2);
	printf("\nSet1^Set2=\n");
	show(intersectionResult);
    getchar();
	return 0;
}