<!DOCTYPE html>
<html>
<head>
  <title>Even or Odd Checker</title>
</head>
<body>

  <h1>Check if a Number is Even or Odd</h1>
  
  <input type="number" id="numberInput" placeholder="Enter a number">
  <button onclick="checkEvenOdd()">Check</button>
  
  <p id="result"></p>

  <script>
    function checkEvenOdd() {
      const num = document.getElementById('numberInput').value; // get value from input
      const number = parseInt(num); // convert to integer

      if (isNaN(number)) {
        document.getElementById('result').innerText = "Please enter a valid number.";
      } else {
        if (number % 2 === 0) {
          document.getElementById('result').innerText = number + " is Even.";
        } else {
          document.getElementById('result').innerText = number + " is Odd.";
        }
      }
    }
  </script>

</body>
</html>
