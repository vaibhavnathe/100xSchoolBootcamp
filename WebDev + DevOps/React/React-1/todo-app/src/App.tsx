

// tsx/jsx can returned this html, js code , but ts can't return html code

// component :- building blocks of UI. They allow you to split UI into independent, reusable piece which is component
// props :- In React, props (short for "properties") are read-only objects used to pass data from a parent component to a child component
// useState :- h\Hook that lets you add state to functional component. It return an array with current state and function to update it.
function App() {

   // write valid ts
   // we will get some data from backend like this json format
  //  const posts = await axios.get("/posts/something")
   const posts = [{
      name: "Hakirat", 
      content : "Hi this is my new Course for WebDev + DevOps"
    },{
      name: "Raman", 
      content : "Hi I started learning ML"
    },
    {
      name: "Shivay", 
      content : "Hi I have enrolled in the cohort 3"
    },
    {
      name: "Sachin", 
      content : "Hi I got a job"
    }
   ];

  //  const postComponents = posts.map(post => <Post name={post.name} content={post.content}/>);

  //  const postComponents = [
  //       <Post name={posts[0].name} content={posts[0].content}/>,
  //       <Post name={posts[1].name} content={posts[1].content}/>
  //  ]


  // Question :- what will/should happen for below code -> First all above posts array get rendered on page, 
  //            & then this setInterval will run for each sec & will add one post(name, content) object 
   //           but the posts will not re-rendered on page coz it only getting pushed to posts array not rendering on page.
   //           Thats why we use useState hook
  setInterval(() => {
    console.log("Set Interval");
    posts.push({
      name: "Kirat",
      content: "Kirat is my name & coding is my game"
    });
    console.log("Posts: " , posts);
  }, 1000);

  return (
    <div>
      <h1>LinkedIn!!!</h1>

      {/* Redenring backend post data */}
      {posts.map(post => <Post name={post.name} content={post.content}/>)}

      {/* OR */}
      
      {/* {postComponents} */}
      
      {/* OR */}
      
      {/* <Post name={posts[0].name} content={posts[0].content}/>
      <Post name={posts[1].name} content={posts[1].content}/> */}
      

      {/* // hardcoded post data */}
      {/* <Post name="Harkirat" content="Hi this is my new Course for WebDev + DevOps"/>
      <Post name="Raman" content="Hi I started learning ML"/>
      <Post name="Shreya" content="Hi I enrolled in cohort 3"/>
      <Post name="Shivam" content="Hi I got a job today"/>
      <Post name="Sachin" content="Hi I got a internship"/> */}
    </div>
  )
}

export default App;

// post component for linkedin
function Post(props)
{
  return (
    <div style={{backgroundColor: "lightblue",margin: "10px", padding: "10px", borderRadius: "4px", fontSize: 20, border: "2px solid black"}}>

      <div>
        <b>{props.name}</b>
      </div>

      <div>
        {props.content}
      </div>

    </div>
  )
}