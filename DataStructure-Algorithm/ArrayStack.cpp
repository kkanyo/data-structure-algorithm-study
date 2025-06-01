#include "ArrayStack.h"

void AS_CreateStack( ArrayStack** stack, int capacity )
{
	*stack = ( ArrayStack* ) malloc( sizeof( ArrayStack ) );

	if ( *stack != nullptr ) {
		( *stack )->Nodes = ( Node* ) malloc( sizeof( Node ) * capacity );

		( *stack )->Capacity = capacity;

		( *stack )->Top = -1;
	}
}

void AS_DestroyStack( ArrayStack* stack )
{
	free( stack->Nodes );

	free( stack );
}

void AS_Push( ArrayStack* stack, ElementType data )
{
	stack->Top++;
	stack->Nodes[stack->Top].Data = data;
}

ElementType AS_Pop( ArrayStack* stack )
{
	int position = stack->Top--;
	return stack->Nodes[position].Data;
}

ElementType AS_Top( ArrayStack* stack )
{
	return stack->Nodes[stack->Top].Data;
}

int AS_GetSize( ArrayStack* stack )
{
	return stack->Top + 1;
}

int AS_IsEmpty( ArrayStack* stack )
{
	return stack->Top == -1;
}

int AS_IsFull( ArrayStack* stack )
{
	return AS_GetSize( stack ) == stack->Capacity;
}
