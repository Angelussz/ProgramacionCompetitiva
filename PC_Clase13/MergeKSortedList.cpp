priority_queue<int,vector<int>, greater<int>> colapri; 

    if(lists.size() == 0) return nullptr;
    
    for(auto i : lists){
        ListNode* iter = i;
        if(iter==nullptr) continue;
        while (iter != nullptr)
        {
            colapri.push(iter->val);
            iter = iter->next;
        }
    }
    if(colapri.size() == 0) return nullptr;

    ListNode* listapri = new ListNode();
    listapri->val = colapri.top();
    colapri.pop();

    ListNode* aux = listapri;
    while (!colapri.empty())
    {
        ListNode* nxt = new ListNode();
        nxt->val = colapri.top();
        aux->next = nxt;
        aux = aux->next;
        colapri.pop();

    }
    return listapri;