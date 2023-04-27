#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;

bool checkInput(string keyNote, vector<string> sharpNotes, vector<string> flatNotes)
{
    for(int i = 0; i < 12; i++)
    {
        if(sharpNotes[i] == keyNote || flatNotes[i] == keyNote || keyNote == "Cb")
        {
            return true;
        }
    }

    return false;
}

//======================== Sort notes ==========================================================================

vector<string> sortNotes(vector<string> notes, string keyNote) //This function sorts all notes from a starting point defined by the user (root key)
{
    int pos = 0, count = 0;
    vector<string> sortedNotes;

    for(int i = 0; i < 12; i++)
    {
        if(notes[i] == keyNote)
        {
            pos = i;
            for (int j = 0; j <= 11 - pos; j++)
            {
                sortedNotes.insert(sortedNotes.end(), notes[pos + j]);
                count++;
            }
            for (int k = 0; k <= 11 - count; k++)
            {
                sortedNotes.insert(sortedNotes.end(), notes[k]);
            }
        }
    }

    return sortedNotes;
}

//======================== Major scale and its exceptions ======================================================

void majorScale(vector<string> sharpNotes, vector<string> flatNotes, string keyNote)
{
    int majorScale[] = {0, 2, 4, 5, 7, 9, 11};
    cout << "Major scale:" << endl;

//-------------------------Sequence with sharp notes------------------------------------------------------------

    if(keyNote == "C" || keyNote == "D" || keyNote == "E" || keyNote == "G" || keyNote == "A" || keyNote == "B")
    {
        for(int i = 0; i < 7; i++)
        {
            cout << sharpNotes[majorScale[i]] << " ";
        }
    }

    else if(keyNote == "F#" || keyNote == "C#") //special case for unusual scales that include E# and B#
    {
        if(keyNote == "F#")
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 6)
                {
                    cout << "E#";
                    continue;
                }
                cout << sharpNotes[majorScale[i]] << " ";
            }
        }

        else
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 2)
                {
                    cout << "E#";
                    continue;
                }

                if(i == 6)
                {
                    cout << "B#";
                    continue;
                }
                cout << sharpNotes[majorScale[i]] << " ";
            }
        }
    }


//--------------------------- Sequence with flat notes ---------------------------------------------------

    if(keyNote == "F" || keyNote == "Bb" || keyNote == "Eb" || keyNote == "Ab" || keyNote == "Db")
    {
        for(int i = 0; i < 7; i++)
        {
            cout << flatNotes[majorScale[i]] << " ";
        }
    }



    else if(keyNote == "Gb" || keyNote == "Cb") //special case for unusual scales that include Fb and Cb
    {
        if(keyNote == "Gb")
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 3)
                {
                    cout << "Cb" << " ";
                    continue;
                }
                cout << flatNotes[majorScale[i]] << " ";
            }
        }

        else if(keyNote == "Cb")
        {
            string specialScaleCb[] = {"Cb","Db","Eb","Fb","Gb","Ab","Bb"};
            for(int i = 0; i < 7; i++)
            {
                cout << specialScaleCb[i] << " ";
            }
        }
    }
    cout << endl;
}//end of majorScale

//======================== Minor scale and its exceptions ======================================================

void minorScale(vector<string> sharpNotes, vector<string> flatNotes, string keyNote)
{
    int minorScale[] = {0, 2, 3, 5, 7, 8, 10};
    cout << "Minor scale:" << endl;

//-------------------------Sequence with sharp notes------------------------------------------------------------

    if(keyNote == "A" || keyNote == "E" || keyNote == "B" || keyNote == "F#" || keyNote == "C#" || keyNote == "G#")
    {
        for(int i = 0; i < 7; i++)
        {
            cout << sharpNotes[minorScale[i]] << " ";
        }
    }

    else if(keyNote == "D#" || keyNote == "A#") //special case for unusual scales that include E# and B#
    {
        if(keyNote == "D#")
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 1)
                {
                    cout << "E#" << " ";
                    continue;
                }
                cout << sharpNotes[minorScale[i]] << " ";
            }
        }

        else
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 1)
                {
                    cout << "B#" <<" ";
                    continue;
                }

                if(i == 4)
                {
                    cout << "E#" << " ";
                    continue;
                }
                cout << sharpNotes[minorScale[i]] << " ";
            }
        }
    }



//-------------------------Sequence with flat notes------------------------------------------------------------

    if(keyNote == "D" || keyNote == "G" || keyNote == "C" || keyNote == "F" || keyNote == "Bb")
    {
        for(int i = 0; i < 7; i++)
        {
            cout << flatNotes[minorScale[i]] << " ";
        }
    }

    else if(keyNote == "Eb" || keyNote == "Ab") //special case for unusual scales that include Fb and Cb
    {
        if(keyNote == "Eb")
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 5)
                {
                    cout << "Cb" << " ";
                    continue;
                }
                cout << flatNotes[minorScale[i]] << " ";
            }
        }

        else if(keyNote == "Ab")
        {
            string specialScaleAb[] = {"Ab","Bb","Cb","Db","Eb","Fb","Gb"};
            for(int i = 0; i < 7; i++)
            {
                cout << specialScaleAb[i] << " ";
            }
        }
    }
    cout << endl;
}//end of minorScale

void harmonicField(vector<string> sharpNotes, vector<string> flatNotes, string keyNote)
{
    int majorScale[] = {0, 2, 4, 5, 7, 9, 11};
    string field[] = {"7M","m7","m7","7M","7","m7","m7/b5"};

    cout << "Major Harmonic field:" << endl;

//-------------------------Sequence with sharp notes------------------------------------------------------------

    if(keyNote == "C" || keyNote == "D" || keyNote == "E" || keyNote == "G" || keyNote == "A" || keyNote == "B")
    {
        for(int i = 0; i < 7; i++)
        {
            cout << sharpNotes[majorScale[i]];
            cout << field[i] << " ";
        }
    }

    else if(keyNote == "F#" || keyNote == "C#") //special case for unusual scales that include E# and B#
    {
        if(keyNote == "F#")
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 6)
                {
                    cout << "E#";
                    cout << field[i] << " ";
                    continue;
                }
                cout << sharpNotes[majorScale[i]];
                cout << field[i] << " ";
            }
        }

        else
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 2)
                {
                    cout << "E#";
                    cout << field[i] << " ";
                    continue;
                }

                if(i == 6)
                {
                    cout << "B#";
                    cout << field[i] << " ";
                    continue;
                }
                cout << sharpNotes[majorScale[i]] << " ";
                cout << field[i] << " ";
            }
        }

    }

//--------------------------- Sequence with flat notes ---------------------------------------------------

    if(keyNote == "F" || keyNote == "Bb" || keyNote == "Eb" || keyNote == "Ab" || keyNote == "Db")
    {
        for(int i = 0; i < 7; i++)
        {
            cout << flatNotes[majorScale[i]];
            cout << field[i] << " ";
        }
    }

    else if(keyNote == "Gb" || keyNote == "Cb") //special case for unusual scales that include Fb and Cb
    {
        if(keyNote == "Gb")
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 3)
                {
                    cout << "Cb";
                    cout << field[i] << " ";
                    continue;
                }
                cout << flatNotes[majorScale[i]] << " ";
                cout << field[i] << " ";
            }
        }

        else if(keyNote == "Cb")
        {
            string specialScaleCb[] = {"Cb7M","Dbm7","Ebm7","Fb7M","Gb7","Abm7","Bbm7/b5"};
            for(int i = 0; i < 7; i++)
            {
                cout << specialScaleCb[i] << " ";
            }
        }
    }

    cout << endl;
}//end of Major harmonic field

void harmonicMinorScale(vector<string> sharpNotes, vector<string> flatNotes, string keyNote)
{
    int minorScale[] = {0, 2, 3, 5, 7, 8, 10};
    cout << "Harmonic minor scale (minor scale with 7M):" << endl;

//-------------------------Sequence with sharp notes------------------------------------------------------------

    if(keyNote == "A" ||keyNote == "E" || keyNote == "B" || keyNote == "F#" || keyNote == "C#" || keyNote == "G#")
    {
        for(int i = 0; i < 7; i++)
        {
            if(i == 6)
            {
                cout << sharpNotes[minorScale[i]] << "#";
                continue;
            }
            cout << sharpNotes[minorScale[i]] << " ";
        }

    }

    else if(keyNote == "D#" || keyNote == "A#") //special case for unusual scales that include E# and B#
    {
        if(keyNote == "D#")
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 6)
                {
                cout << sharpNotes[minorScale[i]] << "#";
                continue;
                }
                if(i == 1)
                {
                    cout << "E#" << " ";
                    continue;
                }
                cout << sharpNotes[minorScale[i]] << " ";
            }
        }

        else
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 6)
                {
                cout << sharpNotes[minorScale[i]] << "#";
                continue;
                }
                if(i == 1)
                {
                    cout << "B#" <<" ";
                    continue;
                }

                if(i == 4)
                {
                    cout << "E#" << " ";
                    continue;
                }
                cout << sharpNotes[minorScale[i]] << " ";
            }
        }
    }



//-------------------------Sequence with flat notes------------------------------------------------------------

    if(keyNote == "D" || keyNote == "G" || keyNote == "C" || keyNote == "F" || keyNote == "Bb")
    {
        for(int i = 0; i < 7; i++)
        {
            if(i == 6)
            {
                cout << sharpNotes[minorScale[i]] << "#";
                continue;
            }
            cout << flatNotes[minorScale[i]] << " ";
        }
    }

    else if(keyNote == "Eb" || keyNote == "Ab") //special case for unusual scales that include Fb and Cb
    {
        if(keyNote == "Eb")
        {
            for(int i = 0; i < 7; i++)
            {
                if(i == 5)
                {
                    cout << "Cb" << " ";
                    continue;
                }
                cout << flatNotes[minorScale[i]] << " ";
            }
        }

        else if(keyNote == "Ab")
        {
            string specialScaleAb[] = {"Ab","Bb","Cb","Db","Eb","Fb","Gb"};
            for(int i = 0; i < 7; i++)
            {
                cout << specialScaleAb[i] << " ";
            }
        }
    }
    cout << endl;
}//end of minorScale


int main()
{
    vector<string> originalSharpNotes = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"}; //Complete chromatic scale with sharp notes
    vector<string> originalFlatNotes = {"C","Db","D","Eb","E","F","Gb","G","Ab","A","Bb","B"};  //Complete chromatic scale with flat notes
    string keyNote;
    string yOrN = "yes";



    while(yOrN == "yes")
    {

    cout << "-- Please enter root key (note + # or b) --" << endl;
    cin >> keyNote;


    keyNote[0] = toupper(keyNote[0]); //uppercase to avoid incorret input from user

    bool check;
    check = checkInput(keyNote, originalSharpNotes, originalFlatNotes);

    while(check == 0)
    {
      cout << "-- Please enter a valid input (note + # or b) --" << endl;
      cin >> keyNote;
      keyNote[0] = toupper(keyNote[0]);
      check = checkInput(keyNote, originalSharpNotes, originalFlatNotes);
    }

    cout << "-------------------------------------------" << endl;

    vector<string> sortedSharpNotes = sortNotes(originalSharpNotes, keyNote);
    vector<string> sortedFlatNotes = sortNotes(originalFlatNotes, keyNote);

    cout << endl;
    majorScale(sortedSharpNotes, sortedFlatNotes, keyNote);
    cout << endl;
    harmonicField(sortedSharpNotes, sortedFlatNotes, keyNote);
    cout << endl;
    minorScale(sortedSharpNotes, sortedFlatNotes, keyNote);
    cout << endl;
    harmonicMinorScale(sortedSharpNotes, sortedFlatNotes, keyNote);
    cout << endl << "-------------------------------------------" << endl;

    }

    return 0;
}
