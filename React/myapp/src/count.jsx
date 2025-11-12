import React, { useState, useEffect } from 'react';

function Counter() {
  // 1. useState Hook:
  // - count is the current state value.
  // - setCount is the function used to update the state.
  // - 0 is the initial state value.
  const [count, setCount] = useState(0);

  // 2. useEffect Hook:
  // This runs *after* every render where the 'count' value has changed.
  // It's used here to update the browser's document title.
  useEffect(() => {
    // This is the "side effect" logic
    document.title = `Count: ${count}`;
    
    // The dependency array [count] tells React to re-run this effect
    // only when the 'count' state variable changes.
  }, [count]); 

  // Handlers to update the state using the setCount function
  const increment = () => {
    // Use the functional update form for reliable state based on the previous state
    setCount(prevCount => prevCount + 1);
  };

  const decrement = () => {
    setCount(prevCount => prevCount - 1);
  };

  return (
    <div style={{ textAlign: 'center', padding: '20px', border: '1px solid #ccc', borderRadius: '8px' }}>
      <h2>Counter App (Hooks)</h2>
      
      {/* Display the current count from the state */}
      <p style={{ fontSize: '3em', margin: '10px 0', fontWeight: 'bold' }}>
        {count}
      </p>
      
      {/* Decrement Button (-) */}
      <button 
        onClick={decrement} 
        style={{ padding: '10px 20px', fontSize: '1.5em', margin: '0 10px', cursor: 'pointer', backgroundColor: '#f44336', color: 'white', border: 'none', borderRadius: '5px' }}
      >
        -
      </button>

      {/* Increment Button (+) */}
      <button 
        onClick={increment} 
        style={{ padding: '10px 20px', fontSize: '1.5em', margin: '0 10px', cursor: 'pointer', backgroundColor: '#4CAF50', color: 'white', border: 'none', borderRadius: '5px' }}
      >
        +
      </button>
    </div>
  );
}

export default Counter;