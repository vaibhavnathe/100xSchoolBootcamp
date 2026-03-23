
// Middleware :- 1) Can Modify req, res objext
//               2) Can end the request-response cycle
//               3) Can call the next() function

// stateful auth :- token get stored in DB and in middleware we call db using access keys and refresh keys

// This is stateless auth :- token get stored in localStorage
 const authMiddleware = (req, res, next) => {
    // check if they have sent the right header, extract who this user is from header.
    const token = req.headers.token;

    // 2) Can end the request-response cycle
    if(!token){
        res.status(403).json({
            message : "You are not logged in"
        });
        return;
    }

    // verify token :- checking if token signed using same private/secret key or not
    const decoded = jwt.verify(token, "harkirat123");
    const username = decoded.username;

    if(!username){
        res.status(403).json({
            message : "malformed token"
        })
    }

    // 1) Can Modify req, res objext
    req.username = username;

    // 3) Can call the next() function
    next();
}

module.exports = {
    authMiddleware
}