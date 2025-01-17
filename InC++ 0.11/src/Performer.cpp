//
//  performer.cpp
//  InC++ 0.07
//
//  Created by Greg White on 30/03/2015.
//
//

#include "Performer.h"
//--------------------------------------------------------------
void Performer::openVirtualPort(string portName) {
    
    // MIDI stuff
    
    // print the available output ports to the console
    midiOut.listPorts(); // via instance
    ofxMidiOut::listPorts(); // via static too
    
    // connect
    //midiOut.openPort(0); // by number
    //midiOut.openPort("IAC Driver Pure Data In"); // by name
    midiOut.openVirtualPort(portName); // open a virtual port
    

}

//--------------------------------------------------------------
void Performer::openPort(int _port) {
    
    // MIDI stuff
    
    // print the available output ports to the console
    midiOut.listPorts(); // via instance
    ofxMidiOut::listPorts(); // via static too
    
    // connect
    midiOut.openPort(0); // by number

    
    
}


//--------------------------------------------------------------
void Performer::setup(int _channel) {

        // Initialise MIDI values
    channel = _channel;
    note = 0;
    velocity = 0;
    
    // Initialise counter values
    currentTime = 0;
    previousTime = 0;
    beatCheck = true;
    
    tempo = 120;
    freq = (tempo/60)/beatsInBar[0];
    
    progress = 0;
    factor = 1;
    
    threshold = 10;
    margMin = -10;
    margMax = 10;
    margin = (int) ofRandom(margMin, margMax);
    
    previousBar = 0;
    
    finished = false;
    
    // Initialise pattern values
    currentBar = 0;
    currentIndex = 0;
    
}

//--------------------------------------------------------------
void Performer::exit() {
    
    // Remember to note where you have imported code!!!
    // Like here!!
    // clean up
    midiOut.closePort();
}

//--------------------------------------------------------------
void Performer::play() {
        
        
        // Calculate speed of phasor
        freq = (tempo/60)/beatsInBar[currentBar]; // Thanks to Kiona H. Niehaus for figuring this calculation out!
        
        // Set phasor
        currentTime = metronome.phasor(freq, 1, beatsInBar[currentBar]+1);
        
        //-------------------------------------------------------------------------------------
        
        // Check to see if phasor has restarted
        // If so, check again for beats
        
        if (currentTime < previousTime){
            
            beatCheck = true;
        }
        
        
        
        if (beatCheck == true){
            
            
            // Check to see if progress counter needs resetting
            if (previousBar != currentBar){
                progress = 0;
                margin = ofRandom(margMin, margMax);
            }
            
            
            // Check if it's time to play a note
            if (currentTime >= time[currentBar][currentIndex]){
                
                
                // Send MIDI notes
                velocity = 100;
                note = pitch[currentBar][currentIndex];
                
                midiOut.sendNoteOn(channel, note, velocity);
                
                
                
                // If there are more notes in the bar, increment current index
                if (currentIndex < pitch[currentBar].size()){
                    
                    currentIndex++;
                    // Had to put inside an if statement, because when currentIndex went above pitch[currentBar].size(), it would send an extra MIDI note (value of 1)
                }
                
                
                // If there are no more notes in the bar, reset current index
                if (currentIndex >= pitch[currentBar].size()){
                    
                    beatCheck = false;
                    currentIndex = 0;

                    
                    progress += beatsInBar[currentBar] * factor; // Using beatsInBar instead of pitch[currentBar].size() because otherwise ghost notes count as full beats
                    previousBar = currentBar;
                    
                    
                    // Check to see if we progress to next bar
                    if (progress >= threshold + margin && currentBar != 53){currentBar++;}
                    
                }
            }
            
        }
        
        // Set previousTime as the current time, so we can check at beginning of the loop
        previousTime = currentTime;
        
        //midiOut << NoteOff(channel, note, velocity);
        
        // Flag when performer has finished last bar
        if (progress >= threshold && currentBar == 53) {finished = true;}
        
    
    
    
}


//--------------------------------------------------------------
void Performer::loadBars() {
    
    // Pitch and time data
    
    // Vectors to store pitch values
    vector<int> p00;
    vector<int> p01;
    vector<int> p02;
    vector<int> p03;
    vector<int> p04;
    vector<int> p05;
    vector<int> p06;
    vector<int> p07;
    vector<int> p08;
    vector<int> p09;
    vector<int> p10;
    vector<int> p11;
    vector<int> p12;
    vector<int> p13;
    vector<int> p14;
    vector<int> p15;
    vector<int> p16;
    vector<int> p17;
    vector<int> p18;
    vector<int> p19;
    vector<int> p20;
    vector<int> p21;
    vector<int> p22;
    vector<int> p23;
    vector<int> p24;
    vector<int> p25;
    vector<int> p26;
    vector<int> p27;
    vector<int> p28;
    vector<int> p29;
    vector<int> p30;
    vector<int> p31;
    vector<int> p32;
    vector<int> p33;
    vector<int> p34;
    vector<int> p35;
    vector<int> p36;
    vector<int> p37;
    vector<int> p38;
    vector<int> p39;
    vector<int> p40;
    vector<int> p41;
    vector<int> p42;
    vector<int> p43;
    vector<int> p44;
    vector<int> p45;
    vector<int> p46;
    vector<int> p47;
    vector<int> p48;
    vector<int> p49;
    vector<int> p50;
    vector<int> p51;
    vector<int> p52;
    vector<int> p53;
    
    
    // Add pitch values to vectors
    
    // C pulse
    p00.push_back(60);
    
    // Bar 1, 2, 3...
    p01.push_back(60);
    p01.push_back(64);
    p01.push_back(60);
    p01.push_back(64);
    p01.push_back(60);
    p01.push_back(64);
    
    p02.push_back(60);
    p02.push_back(64);
    p02.push_back(65);
    p02.push_back(64);
    
    p03.push_back(64);
    p03.push_back(65);
    p03.push_back(64);
    
    p04.push_back(64);
    p04.push_back(65);
    p04.push_back(67);
    
    p05.push_back(64);
    p05.push_back(65);
    p05.push_back(67);
    
    p06.push_back(72);
    
    p07.push_back(60);
    p07.push_back(60);
    p07.push_back(60);
    
    p08.push_back(67);
    p08.push_back(65);
    
    p09.push_back(71);
    p09.push_back(67);
    
    p10.push_back(71);
    p10.push_back(67);
    
    p11.push_back(65);
    p11.push_back(67);
    p11.push_back(71);
    p11.push_back(67);
    p11.push_back(71);
    p11.push_back(67);
    
    p12.push_back(65);
    p12.push_back(67);
    p12.push_back(71);
    p12.push_back(72);
    
    p13.push_back(71);
    p13.push_back(67);
    p13.push_back(67);
    p13.push_back(65);
    p13.push_back(67);
    p13.push_back(67);
    
    p14.push_back(72);
    p14.push_back(71);
    p14.push_back(67);
    p14.push_back(66);
    
    p15.push_back(67);
    
    p16.push_back(67);
    p16.push_back(71);
    p16.push_back(72);
    p16.push_back(71);
    
    p17.push_back(71);
    p17.push_back(72);
    p17.push_back(71);
    p17.push_back(72);
    p17.push_back(71);
    
    p18.push_back(64);
    p18.push_back(66);
    p18.push_back(64);
    p18.push_back(66);
    p18.push_back(64);
    p18.push_back(64);
    
    p19.push_back(79);
    
    p20.push_back(64);
    p20.push_back(66);
    p20.push_back(64);
    p20.push_back(66);
    p20.push_back(55);
    p20.push_back(64);
    p20.push_back(66);
    p20.push_back(64);
    p20.push_back(66);
    p20.push_back(64);
    
    p21.push_back(66);
    
    p22.push_back(64);
    p22.push_back(64);
    p22.push_back(64);
    p22.push_back(64);
    p22.push_back(64);
    p22.push_back(66);
    p22.push_back(67);
    p22.push_back(69);
    p22.push_back(71);
    
    p23.push_back(64);
    p23.push_back(66);
    p23.push_back(66);
    p23.push_back(66);
    p23.push_back(66);
    p23.push_back(66);
    p23.push_back(67);
    p23.push_back(69);
    p23.push_back(71);
    
    p24.push_back(64);
    p24.push_back(66);
    p24.push_back(67);
    p24.push_back(67);
    p24.push_back(67);
    p24.push_back(67);
    p24.push_back(67);
    p24.push_back(69);
    p24.push_back(71);
    
    p25.push_back(64);
    p25.push_back(66);
    p25.push_back(67);
    p25.push_back(69);
    p25.push_back(69);
    p25.push_back(69);
    p25.push_back(69);
    p25.push_back(69);
    p25.push_back(71);
    
    p26.push_back(64);
    p26.push_back(66);
    p26.push_back(67);
    p26.push_back(69);
    p26.push_back(71);
    p26.push_back(71);
    p26.push_back(71);
    p26.push_back(71);
    p26.push_back(71);
    
    p27.push_back(64);
    p27.push_back(66);
    p27.push_back(64);
    p27.push_back(66);
    p27.push_back(67);
    p27.push_back(64);
    p27.push_back(67);
    p27.push_back(66);
    p27.push_back(64);
    p27.push_back(66);
    p27.push_back(64);
    
    p28.push_back(64);
    p28.push_back(66);
    p28.push_back(64);
    p28.push_back(66);
    p28.push_back(64);
    p28.push_back(64);
    
    p29.push_back(64);
    p29.push_back(67);
    p29.push_back(72);
    
    p30.push_back(72);
    
    p31.push_back(67);
    p31.push_back(65);
    p31.push_back(67);
    p31.push_back(71);
    p31.push_back(67);
    p31.push_back(71);
    
    p32.push_back(65);
    p32.push_back(67);
    p32.push_back(65);
    p32.push_back(67);
    p32.push_back(71);
    p32.push_back(65);
    p32.push_back(67);
    
    p33.push_back(67);
    p33.push_back(65);
    
    p34.push_back(67);
    p34.push_back(65);
    
    p35.push_back(65);
    p35.push_back(67);
    p35.push_back(71);
    p35.push_back(67);
    p35.push_back(71);
    p35.push_back(67);
    p35.push_back(71);
    p35.push_back(67);
    p35.push_back(71);
    p35.push_back(67);
    p35.push_back(70);
    p35.push_back(79);
    p35.push_back(81);
    p35.push_back(79);
    p35.push_back(83);
    p35.push_back(81);
    p35.push_back(79);
    p35.push_back(76);
    p35.push_back(79);
    p35.push_back(78);
    p35.push_back(76);
    p35.push_back(77);
    
    p36.push_back(65);
    p36.push_back(67);
    p36.push_back(71);
    p36.push_back(67);
    p36.push_back(71);
    p36.push_back(67);
    
    p37.push_back(65);
    p37.push_back(67);
    
    p38.push_back(65);
    p38.push_back(67);
    p38.push_back(71);
    
    p39.push_back(71);
    p39.push_back(67);
    p39.push_back(65);
    p39.push_back(67);
    p39.push_back(71);
    p39.push_back(72);
    
    p40.push_back(71);
    p40.push_back(65);
    
    p41.push_back(71);
    p41.push_back(67);
    
    p42.push_back(72);
    p42.push_back(71);
    p42.push_back(68);
    p42.push_back(72);
    
    p43.push_back(77);
    p43.push_back(76);
    p43.push_back(77);
    p43.push_back(76);
    p43.push_back(76);
    p43.push_back(76);
    p43.push_back(76);
    p43.push_back(77);
    p43.push_back(76);
    
    p44.push_back(77);
    p44.push_back(76);
    p44.push_back(76);
    p44.push_back(72);
    
    p45.push_back(74);
    p45.push_back(74);
    p45.push_back(67);
    
    p46.push_back(67);
    p46.push_back(74);
    p46.push_back(76);
    p46.push_back(74);
    p46.push_back(67);
    p46.push_back(67);
    p46.push_back(67);
    p46.push_back(67);
    p46.push_back(74);
    p46.push_back(76);
    p46.push_back(74);
    
    p47.push_back(74);
    p47.push_back(76);
    p47.push_back(74);
    
    p48.push_back(67);
    p48.push_back(67);
    p48.push_back(65);
    
    p49.push_back(65);
    p49.push_back(67);
    p49.push_back(70);
    p49.push_back(67);
    p49.push_back(70);
    p49.push_back(67);
    
    p50.push_back(65);
    p50.push_back(67);
    
    p51.push_back(65);
    p51.push_back(67);
    p51.push_back(70);
    
    p52.push_back(67);
    p52.push_back(70);
    
    p53.push_back(70);
    p53.push_back(67);
    
    
    
    // Add bar vectors to main pitch vector
    pitch.push_back(p00);
    pitch.push_back(p01);
    pitch.push_back(p02);
    pitch.push_back(p03);
    pitch.push_back(p04);
    pitch.push_back(p05);
    pitch.push_back(p06);
    pitch.push_back(p07);
    pitch.push_back(p08);
    pitch.push_back(p09);
    pitch.push_back(p10);
    pitch.push_back(p11);
    pitch.push_back(p12);
    pitch.push_back(p13);
    pitch.push_back(p14);
    pitch.push_back(p15);
    pitch.push_back(p16);
    pitch.push_back(p17);
    pitch.push_back(p18);
    pitch.push_back(p19);
    pitch.push_back(p20);
    pitch.push_back(p21);
    pitch.push_back(p22);
    pitch.push_back(p23);
    pitch.push_back(p24);
    pitch.push_back(p25);
    pitch.push_back(p26);
    pitch.push_back(p27);
    pitch.push_back(p28);
    pitch.push_back(p29);
    pitch.push_back(p30);
    pitch.push_back(p31);
    pitch.push_back(p32);
    pitch.push_back(p33);
    pitch.push_back(p34);
    pitch.push_back(p35);
    pitch.push_back(p36);
    pitch.push_back(p37);
    pitch.push_back(p38);
    pitch.push_back(p39);
    pitch.push_back(p40);
    pitch.push_back(p41);
    pitch.push_back(p42);
    pitch.push_back(p43);
    pitch.push_back(p44);
    pitch.push_back(p45);
    pitch.push_back(p46);
    pitch.push_back(p47);
    pitch.push_back(p48);
    pitch.push_back(p49);
    pitch.push_back(p50);
    pitch.push_back(p51);
    pitch.push_back(p52);
    pitch.push_back(p53);
    
    // Vectors to store time values
    vector<float> t00;
    vector<float> t01;
    vector<float> t02;
    vector<float> t03;
    vector<float> t04;
    vector<float> t05;
    vector<float> t06;
    vector<float> t07;
    vector<float> t08;
    vector<float> t09;
    vector<float> t10;
    vector<float> t11;
    vector<float> t12;
    vector<float> t13;
    vector<float> t14;
    vector<float> t15;
    vector<float> t16;
    vector<float> t17;
    vector<float> t18;
    vector<float> t19;
    vector<float> t20;
    vector<float> t21;
    vector<float> t22;
    vector<float> t23;
    vector<float> t24;
    vector<float> t25;
    vector<float> t26;
    vector<float> t27;
    vector<float> t28;
    vector<float> t29;
    vector<float> t30;
    vector<float> t31;
    vector<float> t32;
    vector<float> t33;
    vector<float> t34;
    vector<float> t35;
    vector<float> t36;
    vector<float> t37;
    vector<float> t38;
    vector<float> t39;
    vector<float> t40;
    vector<float> t41;
    vector<float> t42;
    vector<float> t43;
    vector<float> t44;
    vector<float> t45;
    vector<float> t46;
    vector<float> t47;
    vector<float> t48;
    vector<float> t49;
    vector<float> t50;
    vector<float> t51;
    vector<float> t52;
    vector<float> t53;
    
    
    // Add time values to vectors
    
    // C pulse
    t00.push_back(1);
    
    // Bar 1, 2, 3...

    
    t01.push_back(1);
    t01.push_back(1.9);
    t01.push_back(2);
    t01.push_back(2.9);
    t01.push_back(3);
    t01.push_back(3.9);
    
    t02.push_back(1);
    t02.push_back(1.1);
    t02.push_back(1.6);
    t02.push_back(2.1);
    
    t03.push_back(1.5);
    t03.push_back(2);
    t03.push_back(2.5);
    
    t04.push_back(1.5);
    t04.push_back(2);
    t04.push_back(2.5);
    
    t05.push_back(1);
    t05.push_back(1.5);
    t05.push_back(2);
    
    t06.push_back(1);
    
    t07.push_back(4.5);
    t07.push_back(5);
    t07.push_back(5.5);
    
    t08.push_back(1);
    t08.push_back(7);
    
    t09.push_back(1);
    t09.push_back(1.5);
    
    t10.push_back(1);
    t10.push_back(1.5);
    
    t11.push_back(1);
    t11.push_back(1.25);
    t11.push_back(1.5);
    t11.push_back(1.75);
    t11.push_back(2);
    t11.push_back(2.25);
    
    t12.push_back(1);
    t12.push_back(1.5);
    t12.push_back(2);
    t12.push_back(6);
    
    t13.push_back(1);
    t13.push_back(1.25);
    t13.push_back(2);
    t13.push_back(2.25);
    t13.push_back(2.5);
    t13.push_back(3.75);
    
    t14.push_back(1);
    t14.push_back(5);
    t14.push_back(9);
    t14.push_back(13);
    
    t15.push_back(1);
    
    t16.push_back(1);
    t16.push_back(1.25);
    t16.push_back(1.5);
    t16.push_back(1.75);
    
    t17.push_back(1);
    t17.push_back(1.25);
    t17.push_back(1.5);
    t17.push_back(1.75);
    t17.push_back(2);
    
    t18.push_back(1);
    t18.push_back(1.25);
    t18.push_back(1.5);
    t18.push_back(1.75);
    t18.push_back(2);
    t18.push_back(2.75);
    
    t19.push_back(2.5);
    
    t20.push_back(1);
    t20.push_back(1.25);
    t20.push_back(1.5);
    t20.push_back(1.75);
    t20.push_back(2);
    t20.push_back(2.75);
    t20.push_back(3);
    t20.push_back(3.25);
    t20.push_back(3.5);
    t20.push_back(3.75);
    
    t21.push_back(1);
    
    t22.push_back(1);
    t22.push_back(2.5);
    t22.push_back(4);
    t22.push_back(5.5);
    t22.push_back(7);
    t22.push_back(8.5);
    t22.push_back(10);
    t22.push_back(11.5);
    t22.push_back(13);
    
    t23.push_back(1);
    t23.push_back(1.5);
    t23.push_back(3);
    t23.push_back(4.5);
    t23.push_back(6);
    t23.push_back(7.5);
    t23.push_back(9);
    t23.push_back(10.5);
    t23.push_back(12);
    
    t24.push_back(1);
    t24.push_back(1.5);
    t24.push_back(2);
    t24.push_back(3.5);
    t24.push_back(5);
    t24.push_back(6.5);
    t24.push_back(8);
    t24.push_back(9.5);
    t24.push_back(11);
    
    t25.push_back(1);
    t25.push_back(1.5);
    t25.push_back(2);
    t25.push_back(2.5);
    t25.push_back(4);
    t25.push_back(5.5);
    t25.push_back(7);
    t25.push_back(8.5);
    t25.push_back(10);
    
    t26.push_back(1);
    t26.push_back(1.5);
    t26.push_back(2);
    t26.push_back(2.5);
    t26.push_back(3);
    t26.push_back(4.5);
    t26.push_back(6);
    t26.push_back(7.5);
    t26.push_back(9);
    
    t27.push_back(1);
    t27.push_back(1.25);
    t27.push_back(1.5);
    t27.push_back(1.75);
    t27.push_back(2);
    t27.push_back(2.25);
    t27.push_back(2.75);
    t27.push_back(3);
    t27.push_back(3.25);
    t27.push_back(3.5);
    t27.push_back(3.75);
    
    t28.push_back(1);
    t28.push_back(1.25);
    t28.push_back(1.5);
    t28.push_back(1.75);
    t28.push_back(2);
    t28.push_back(2.75);
    
    t29.push_back(1);
    t29.push_back(4);
    t29.push_back(7);
    
    t30.push_back(1);
    
    t31.push_back(1);
    t31.push_back(1.25);
    t31.push_back(1.5);
    t31.push_back(1.75);
    t31.push_back(2);
    t31.push_back(2.25);
    
    t32.push_back(1);
    t32.push_back(1.25);
    t32.push_back(1.5);
    t32.push_back(1.75);
    t32.push_back(2);
    t32.push_back(2.25);
    t32.push_back(2.5);
    t32.push_back(5.5);
    
    t33.push_back(1);
    t33.push_back(1.25);
    
    t34.push_back(1);
    t34.push_back(1.25);
    
    t35.push_back(1);
    t35.push_back(1.25);
    t35.push_back(1.5);
    t35.push_back(1.75);
    t35.push_back(2);
    t35.push_back(2.25);
    t35.push_back(2.5);
    t35.push_back(2.75);
    t35.push_back(3);
    t35.push_back(3.25);
    t35.push_back(7);
    t35.push_back(8);
    t35.push_back(11);
    t35.push_back(11.5);
    t35.push_back(12.5);
    t35.push_back(13);
    t35.push_back(14.5);
    t35.push_back(15);
    t35.push_back(18);
    t35.push_back(18.5);
    t35.push_back(24.5);
    t35.push_back(27);
    
    t36.push_back(1);
    t36.push_back(1.25);
    t36.push_back(1.5);
    t36.push_back(1.75);
    t36.push_back(2);
    t36.push_back(2.25);
    
    t37.push_back(1);
    t37.push_back(1.25);
    
    t38.push_back(1);
    t38.push_back(1.25);
    t38.push_back(1.5);
    
    t39.push_back(1);
    t39.push_back(1.25);
    t39.push_back(1.5);
    t39.push_back(1.75);
    t39.push_back(2);
    t39.push_back(2.25);
    
    t40.push_back(1);
    t40.push_back(1.25);
    
    t41.push_back(1);
    t41.push_back(1.25);
    
    t42.push_back(1);
    t42.push_back(5);
    t42.push_back(9);
    t42.push_back(13);
    
    t43.push_back(1);
    t43.push_back(1.25);
    t43.push_back(1.5);
    t43.push_back(1.75);
    t43.push_back(2);
    t43.push_back(2.5);
    t43.push_back(3);
    t43.push_back(3.25);
    t43.push_back(3.75);
    
    t44.push_back(1);
    t44.push_back(1.5);
    t44.push_back(2.5);
    t44.push_back(3);
    
    t45.push_back(1);
    t45.push_back(2);
    t45.push_back(3);
    
    t46.push_back(1);
    t46.push_back(1.25);
    t46.push_back(1.5);
    t46.push_back(1.75);
    t46.push_back(2.5);
    t46.push_back(3.5);
    t46.push_back(4.5);
    t46.push_back(5);
    t46.push_back(5.25);
    t46.push_back(5.5);
    t46.push_back(5.75);
    
    t47.push_back(1);
    t47.push_back(1.25);
    t47.push_back(1.5);
    
    t48.push_back(1);
    t48.push_back(7);
    t48.push_back(11);
    
    t49.push_back(1);
    t49.push_back(1.25);
    t49.push_back(1.5);
    t49.push_back(1.75);
    t49.push_back(2);
    t49.push_back(2.25);
    
    t50.push_back(1);
    t50.push_back(1.25);
    
    t51.push_back(1);
    t51.push_back(1.25);
    t51.push_back(1.5);
    
    t52.push_back(1);
    t52.push_back(1.25);
    
    t53.push_back(1);
    t53.push_back(1.25);
    
    
    // Add bar vectors to main time vector
    time.push_back(t00);
    time.push_back(t01);
    time.push_back(t02);
    time.push_back(t03);
    time.push_back(t04);
    time.push_back(t05);
    time.push_back(t06);
    time.push_back(t07);
    time.push_back(t08);
    time.push_back(t09);
    time.push_back(t10);
    time.push_back(t11);
    time.push_back(t12);
    time.push_back(t13);
    time.push_back(t14);
    time.push_back(t15);
    time.push_back(t16);
    time.push_back(t17);
    time.push_back(t18);
    time.push_back(t19);
    time.push_back(t20);
    time.push_back(t21);
    time.push_back(t22);
    time.push_back(t23);
    time.push_back(t24);
    time.push_back(t25);
    time.push_back(t26);
    time.push_back(t27);
    time.push_back(t28);
    time.push_back(t29);
    time.push_back(t30);
    time.push_back(t31);
    time.push_back(t32);
    time.push_back(t33);
    time.push_back(t34);
    time.push_back(t35);
    time.push_back(t36);
    time.push_back(t37);
    time.push_back(t38);
    time.push_back(t39);
    time.push_back(t40);
    time.push_back(t41);
    time.push_back(t42);
    time.push_back(t43);
    time.push_back(t44);
    time.push_back(t45);
    time.push_back(t46);
    time.push_back(t47);
    time.push_back(t48);
    time.push_back(t49);
    time.push_back(t50);
    time.push_back(t51);
    time.push_back(t52);
    time.push_back(t53);
}