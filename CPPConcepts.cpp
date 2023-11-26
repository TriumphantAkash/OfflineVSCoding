#include<iostream>
#include<memory>

using namespace std;

//version 1 (Raw pointer) //not recommended

void UseRawPointer()
{
    Song* pSong = new Song("Song song");

    delete pSong;
}

void UseSmartPointer()
{
    //Declare a smart pointer on stack and pass it the raw pointer
    unique_ptr<Song> song2(new Song("song song!!"));

}//song2 is deleted automatically here

208 - 25 Trailwood Dr, Mississauga, ON L4Z 3K9