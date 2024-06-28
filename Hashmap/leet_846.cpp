/*isme hamne pahle check kiya hai ki map me push kiya and then we sort the values
after that becuase hame vo consecutive chahiye for ex.[2,1] and groupsize=2
if we dont sort them then 2+1=3 which is not present but if we sort them then [1,2] and it is present
then if the current value is 0 that means it is already deducted from the map soo continue
now if it is not then you run a loop till the size of group and then
if we have not found the consecutive element then return false else deduct the element from the map*/

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> countMap;
        for (int card : hand)
        {
            countMap[card]++;
        }

        sort(hand.begin(), hand.end());

        for (int i = 0; i < hand.size(); i++)
        {
            if (countMap[hand[i]] == 0)
            { // if it zero then also we can consider no need to erase it from the map

                continue;
            }

            for (int j = 0; j < groupSize; j++)
            {
                int currCard = hand[i] + j;

                if (countMap[currCard] == 0)
                {
                    return false;
                }

                countMap[currCard]--;
            }
        }

        return true;
    }
};