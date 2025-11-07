import React, { useState } from "react";
import "./St.css";

function St() {
  const [students, setStudents] = useState([
    { id: 1, name: "Alice" },
    { id: 2, name: "Bob" },
  ]);

  const [id, setId] = useState("");
  const [name, setName] = useState("");

  const addStudent = () => {
    if (!id || !name) {
      alert("Please enter both ID and name");
      return;
    }

    const idNum = Number(id);
    if (students.some(student => student.id === idNum)) {
      alert("ID already exists!");
      return;
    }

    setStudents([...students, { id: idNum, name }]);
    setId("");
    setName("");
  };

  const deleteStudent = (idToDelete) => {
    setStudents(students.filter(student => student.id !== idToDelete));
  };

  return (
    <div className="student-container">
      <h2 className="student-title">Student List</h2>

      <div className="student-form">
        <input
          type="number"
          placeholder="Enter ID"
          value={id}
          onChange={e => setId(e.target.value)}
        />
        <input
          type="text"
          placeholder="Enter Name"
          value={name}
          onChange={e => setName(e.target.value)}
        />
        <button onClick={addStudent}>Add Student</button>
      </div>

      <ul>
        {students.map(student => (
          <li key={student.id}>
            {student.id}. {student.name}{" "}
            <button
              className="delete-btn"
              onClick={() => deleteStudent(student.id)}
            >
              Delete
            </button>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default St;
