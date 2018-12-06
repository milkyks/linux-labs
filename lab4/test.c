long double f(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * f(n-1);
	}
}

int main()
{
	const int N =  1000;
	for (int i = 0; i < N; i++)
	{
		f(i);
	}
return 0;
}
