   vector<ListNode*> splitListToParts(ListNode* head, int k) {
      int count = 0;
    ListNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    
    // Step 2: Determine the size of each part and how many parts need an extra node
    int partSize = count / k; // Minimum size of each part
    int extra = count % k;    // Number of parts that need an extra node

    vector<ListNode*> ans(k, nullptr);
    ListNode* curr = head;
    
    for (int i = 0; i < k && curr; i++) {
        ans[i] = curr;
        int currentPartSize = partSize + (extra > 0 ? 1 : 0); // Extra node if needed
        extra--;

        // Move `curr` to the end of the current part
        for (int j = 1; j < currentPartSize; j++) {
            if (curr) {
                curr = curr->next;
            }
        }
        
        // Break the current part from the rest of the list
        if (curr) {
            ListNode* nextPart = curr->next;
            curr->next = nullptr; // End the current part
            curr = nextPart;      // Move to the next part
        }
    }

    return ans;
    }