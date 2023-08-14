/*
Cutting rod..

price = []
len = []

formula is
max = 0
if(len == 1)
{
    return price[0];
}
for(cut 1-->len)
{
sum = price[cut]+cutting_rod(len-cut);
maxSum = max(maxSum,sum);
}
*/