/* Stock Span

Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].

*/

#include <stack>
int *stockSpan(int *price, int size)
{

    stack<int> s1;

    int *ans = new int[size];

    s1.push(0);
    ans[0] = 1;

    for (int i = 1; i < size; i++)
    {

        if (price[i] <= price[i - 1])
        {

            s1.push(i);
            ans[i] = 1;
        }
        else
        {

            while (!s1.empty() && price[s1.top()] < price[i])
            {

                s1.pop();
            }

            if (s1.empty())
            {

                s1.push(i);
                ans[i] = i + 1;
            }
            else
            {

                ans[i] = i - s1.top();
                s1.push(i);
            }
        }
    }

    return ans;
}