#include<iostream>
#include<cctype>

using namespace std;

//*************************************
//  isValidUppercaseStateCode
//*************************************

// Return true if the argument is a two-uppercase-letter state code, or
// false otherwise.

bool isValidUppercaseStateCode(string stateCode)
{
    const string codes =
	"AL.AK.AZ.AR.CA.CO.CT.DE.DC.FL.GA.HI.ID.IL.IN.IA.KS."
        "KY.LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC."
        "ND.OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
	    stateCode.find('.') == string::npos  &&  // no '.' in stateCode
        codes.find(stateCode) != string::npos);  // match found
}

bool hasCorrectSyntax(string pollData)
{
    char tester = 's'; //this tells us about type of data which is supposed to
                        //be there. s for state, v for votes and p for party
    bool breaker = true;
    int i = 0;
    while(i < pollData.length())
    {
        switch(tester)
        {
            case 's':
            if(i+1 < pollData.length())
            {
                string temp = ""; temp+=pollData[i]; temp+=pollData[i+1];
                tester = 'v'; i += 2;
                if(!isValidUppercaseStateCode(temp))
                {
                    breaker = false;
                    i = pollData.length();
                }
            }
            else
            {
                breaker = false;
                i = pollData.length();
            }
            break;

            case 'v':
            if(isdigit(pollData[i]))
            {
                if(i+1 < pollData.length())
                {
                    if(isdigit(pollData[i+1]))
                    {
                        i+=2;
                    }
                }
                else
                {
                    i++;
                }
            }
            else
            {
                breaker = false;
                i = pollData.length();
            }
            break;

            case 'p':
            if(isalpha(pollData[i]))
            {
                i++;
            }
            else
            {
                breaker = false;
                i = pollData.length();
            }
            break;
        }
    }

    return breaker;
}

int countVotes(string pollData, char party, int& voteCount)
{
    if(!hasCorrectSyntax(pollData))
        return 1;
    else
        cout<<"chala";
    if(!isalpha(party))
        return 3;

    int i = 2;

    int votes = 0;

    while(i < pollData.length())
    {
        if(isdigit(pollData[i+1]))
        {
            int tempVotes;
            string temp = ""; temp+= pollData[i]; temp+= pollData[i+1]; tempVotes = stoi(temp);
            if(tempVotes == 0)
            {
                return 2;
            }
            else if(pollData[i+2] == party)
            {
                votes += tempVotes;
            }
            i+=5;
        }
        else
        {
            if(pollData[i] == '0')
                return 2;
            else
            {
                if(pollData[i+1] == party)
                {
                    string temp = ""; temp+=pollData[i]; votes += stoi(temp);
                }
                i+=4;
            }
        }
    }
    
    voteCount = votes;
    return 0;
}

int main()
{
    int voteCount = 0; char party; string inpit; cin>>inpit; cout<<"party: "; cin>>party; 
    countVotes(inpit, tolower(party), voteCount);
    cout<<voteCount;
    return 0;
}
