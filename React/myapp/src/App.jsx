import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import St from "./st.jsx";
import Ran from"./ran.jsx";
function App() {
  const [count, setCount] = useState(0)

  return (
    <div> 
      <Ran />
      <St />
    </div>
  )
}

export default App;

