import React from "react";

// Defining the context
export const setTodosContext = React.createContext({setTodos: () => {}, darkTheme: false} as any);
