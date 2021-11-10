var placeOne = document.querySelector(".place-01");
var placeTwo = document.querySelector(".place-02");
var placeThree = document.querySelector(".place-03");

let valuePlace = {
  valueOne: 0,
  valueTwo: 0,
  valueThree: 0
};

const socket = io("ws://192.168.43.6:3000"/*IP addres de server*/, { transports: ["websocket"] });

socket.on("photoResistor", prState => {
  valuePlace.valueOne = prState;

  if (valuePlace.valueOne === 0) {
    placeOne.style.cssText = "background-color: green;";
  } else {
    placeOne.style.cssText = "background-color: red;";
  }
  if (valuePlace.valueTwo === 0) {
    placeTwo.style.cssText = "background-color: green;";
  } else {
    placeTwo.style.cssText = "background-color: red;";
  }
  if (valuePlace.valueThree === 0) {
    placeThree.style.cssText = "background-color: green;";
  } else {
    placeThree.style.cssText = "background-color: red;";
  }
});