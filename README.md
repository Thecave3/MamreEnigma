# MamreEnigma
A simple service to track when our parish library is opened.


#What is
This repository contains my personal project to give a service to whoever wants to know if our parish library is open or not.

#Architecture
* Server side: nodejs server that has two API REST call enabled:
  - GET /getState : Current state of the library
    - Return a JSON Object with the current state of the library and last time updated
      - Info are represented by these fields: state, time and date.
    - Fields required: None
    Please note that this call will be implicit and internal to the server when this service will be exposed to the public, but I can consider to leave this to give a comfortable way to 3rd part services.

  - POST /updateState : Update the status of the library
    - Return a JSON Object with "OK" if the service has accepted the status update request, "NO" otherwise.
      - Info is represented by this field: return_state.
    - Fields required (in a JSON Object): secret_id , that represents the unique code of access (only present in the button) to guarantee authenticity and validity of the message, state , that represents the actual state of the library.
    Please note that state could be only "true" or "false".

* Button side: nodeMCU microcontroller coded with C (nodeMCU is an arduino like) with one button and a led representing the library's status. At the switch of the button the controller will do the PUT call described above.

#Useful links

- [Here](http://www.andrealacava.com:3002/) you can find the service running.

- [Here](http://www.sanfrumenzio.it/home.asp) you can find more informations about the parish.

- [Here](https://www.facebook.com/mamregiovani/) you can find more informations about the library.
