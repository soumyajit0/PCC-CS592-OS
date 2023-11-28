struct Buffer
{
	int data;
	struct Buffer *next;
};

struct Buffer *buffer=NULL;

void insert(int n)
{
	struct Buffer *temp=(struct Buffer *)malloc(sizeof(struct Buffer));
	temp->data=n;
	temp->next=NULL;
	if (buffer==NULL)
	{
		buffer=temp;
	}
	else{
		struct Buffer *ptr=buffer;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}

void delete()
{
	struct Buffer *temp=buffer->next;
	free(buffer);
	buffer=temp;
}
