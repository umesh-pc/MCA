const con = require('./conn.js');

// SQL query to insert one record
const sql = "INSERT INTO T_db.students (rollno, name) VALUES (4, 'umesh')";

    con.query(sql, (err, result) => {
  if (err) throw err;
  console.log('Record inserted successfully!');
    con.end(); // close the connection
});