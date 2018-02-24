# examples

This is a repository for testing various solutions we need to proceed with the project development. Feel free to play around, but if it is specific to your task, please create a new directory before starting, naming it something relating to your feature. This way, we avoid merge conflicts when you push it to the central repository.

# Protocol tutorial

To test sending and receiving protocol messages, do the following:

1. Install dependencies, run the script ```install_dependencies```

2. Go into the sender-receiver directory

3. Create a build directory if it is your first time or if it somehow got deleted

```mkdir build```

4. Go into the build directory and run:

```cmake ..```

And then...

```make```

You should now have three executable files: examples-receiver, examples-sender and examples-test. Start the examples-receiver in one terminal, open a new one and start examples-sender and PLEASE READ ON BEFORE CONTINUING.

examples-receiver will now listen for messages sent by examples-sender. Go to the examples-sender terminal and input any number. The number you input should show up in the examples-receiver terminal as "Receiver: <your number>".
  
There you go! Now look at the code!

```messages.odvd``` contains the specification, start there. Then look at ```sender.cpp``` and ```receiver.cpp``` to see the implementation behind sending and receiving the protocol message in ```messages.odvd```

# Multicast tutorial

To test out how multicasting will be used in this project, go into examples/sender-receiver-multicast and perform the same build operations as above (make build dir cmake... etc).

To see the multicast messages in action, open at *least* three terminal windows.

Start the ```./examples-multicast-receiver``` in at least two terminal windows. This will simulate two different cars connecting to the same message relay. The project cars will be listening on the same address, specified by the V2V protocol, where messages will be sent and all cars listening will get them.

Start ```./examples-multicast-sender``` which works just like the previous tutorial and enter a number to send. Once you've pressed enter, go to the other terminal windows and check the output, there should now be messages in all windows you opened saying: "Received multicast message: <the number you entered>".
