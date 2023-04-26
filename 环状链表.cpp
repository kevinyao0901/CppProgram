#include<bits/stdc++.h>
using namespace std;

typedef struct ListNode {
    int val;//域中元素值
    struct ListNode* next;//指向后继元素
}Linklist;

Linklist* CreateLinklist(int input[], int n) {
    //创建头指针
    Linklist* start = NULL;
    Linklist* temp = (Linklist*)malloc(sizeof(Linklist));
    Linklist* pos = NULL;

    temp->val = input[0];
    temp->next = NULL;

    start = temp;//头指针指向元节点

    int pos_val = input[n - 1] % (n - 1);

    for (int i = 1; i < n; i++) {
        //创建新节点并赋值
        Linklist* a = (Linklist*)malloc(sizeof(Linklist));
        if (i != n - 1) {
            a->val = input[i];
            a->next = NULL;
            temp->next = a;
            temp = a;
            if (pos_val == i) {
                pos = temp;
            }
        }
        else {
            a->val = input[i];
            if (pos_val != 0) {
                a->next = pos;
            }
            else {
                a->next = NULL;
            }
            temp->next = a;
            temp = a;
        }

    }
    return start;
}

int main()
{
    int n;
    cin >> n;
    int input[1000];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    Linklist* start = CreateLinklist(input, n);
    Linklist* temp = start;

    /*相遇时：
        slow指针走过的节点数为 : x + y
        fast指针走过的节点数： x + y + n(y + z)，n为fast指针在环内走了n圈才遇到slow指针， （y + z）为 一圈内节点的个数
        因为fast指针是一步走两个节点，slow指针一步走一个节点， 所以 fast指针走过的节点数 = slow指针走过的节点数 * 2
        (x + y) * 2 = x + y + n(y + z)
        两边消掉一个（x + y）: x + y = n(y + z)
        因为我们要找环形的入口，那么要求的是x，因为x表示 头结点到 环形入口节点的的距离。
        所以我们要求x ，将x单独放在左面：x = n(y + z) - y
        在从n(y + z)中提出一个 （y + z）来，整理公式之后为如下公式：
        x = (n - 1) (y + z) + z 注意这里n一定是大于等于1的，因为 fast指针至少要多走一圈才能相遇slow指针
        这个公式说明什么呢，
        先拿n为1的情况来举例，意味着fast指针在环形里转了一圈之后，就遇到了 slow指针了。
        当 n为1的时候，公式就化解为 x = z
        这就意味着，从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 
        那么当这两个指针相遇的时候就是 环形入口的节点*/


    //TODO 实现一个函数找出链表中环的位置
    Linklist* fast = temp;
    Linklist* slow = temp;
    while (1)
    {
        if (not(fast && fast->next))
        {
            cout << -1;
            return;
        }
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    fast = start;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    cout << fast->val;
    return 0;
}