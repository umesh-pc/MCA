const con = require('./conn.js'); // your MySQL connection

// Query to get all rows
const sql = "SELECT * FROM T_db.students";

con.query(sql, (err, results) => {
  if (err) throw err;

  console.log("Student Records:");
  console.table(results); // prints a nice table in console

  con.end(); // close connection
});
