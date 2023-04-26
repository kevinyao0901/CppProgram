#include<bits/stdc++.h>
using namespace std;

typedef struct ListNode {
    int val;//����Ԫ��ֵ
    struct ListNode* next;//ָ����Ԫ��
}Linklist;

Linklist* CreateLinklist(int input[], int n) {
    //����ͷָ��
    Linklist* start = NULL;
    Linklist* temp = (Linklist*)malloc(sizeof(Linklist));
    Linklist* pos = NULL;

    temp->val = input[0];
    temp->next = NULL;

    start = temp;//ͷָ��ָ��Ԫ�ڵ�

    int pos_val = input[n - 1] % (n - 1);

    for (int i = 1; i < n; i++) {
        //�����½ڵ㲢��ֵ
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

    /*����ʱ��
        slowָ���߹��Ľڵ���Ϊ : x + y
        fastָ���߹��Ľڵ����� x + y + n(y + z)��nΪfastָ���ڻ�������nȦ������slowָ�룬 ��y + z��Ϊ һȦ�ڽڵ�ĸ���
        ��Ϊfastָ����һ���������ڵ㣬slowָ��һ����һ���ڵ㣬 ���� fastָ���߹��Ľڵ��� = slowָ���߹��Ľڵ��� * 2
        (x + y) * 2 = x + y + n(y + z)
        ��������һ����x + y��: x + y = n(y + z)
        ��Ϊ����Ҫ�һ��ε���ڣ���ôҪ�����x����Ϊx��ʾ ͷ��㵽 ������ڽڵ�ĵľ��롣
        ��������Ҫ��x ����x�����������棺x = n(y + z) - y
        �ڴ�n(y + z)�����һ�� ��y + z����������ʽ֮��Ϊ���¹�ʽ��
        x = (n - 1) (y + z) + z ע������nһ���Ǵ��ڵ���1�ģ���Ϊ fastָ������Ҫ����һȦ��������slowָ��
        �����ʽ˵��ʲô�أ�
        ����nΪ1���������������ζ��fastָ���ڻ�����ת��һȦ֮�󣬾������� slowָ���ˡ�
        �� nΪ1��ʱ�򣬹�ʽ�ͻ���Ϊ x = z
        �����ζ�ţ���ͷ������һ��ָ�룬�������ڵ� Ҳ����һ��ָ�룬������ָ��ÿ��ֻ��һ���ڵ㣬 
        ��ô��������ָ��������ʱ����� ������ڵĽڵ�*/


    //TODO ʵ��һ�������ҳ������л���λ��
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