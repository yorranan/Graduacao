import { BrowserRouter, Routes, Route, BrowserRouterProps } from "react-router-dom";

import Home from './pages/Home';
import Details from "./pages/Details";
import CreateNewRecipe from "./pages/CreateNewRecipe";
import Erro from "./pages/Erro";

import Header from "./components/Header";

function RoutesApp()  {
    return(
        <BrowserRouter>
            <Header/>
            <Routes>
                <Route path="/" element={<Home/>}/>
                <Route path="/receita/:id" element={<Details/>}/>
                <Route path="/criar" element={<CreateNewRecipe/>}/>
                <Route path="*" element={<Erro/>}/>
            </Routes>
        </BrowserRouter>
    )
}

export default RoutesApp;