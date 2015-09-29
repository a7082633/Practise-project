class CStack
{
	int m_iData[10];
	int m_top;
public:
	CStack();
	void push(int a);
	void pop();
	int top();
	bool IsFull();
	bool IsEmpty();
};