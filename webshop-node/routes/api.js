//npc moduli za komunikaciju sa blockchain-om
//express je framevork za definisanje logike servera
//definisemo router

const express = require("express");
const router = express.Router();
const { Api, JsonRps, JsSignatureProvider } = require("ineryjs");
//@param {tip} naziv_promenjive_kojoj_definisemo_tip
/**
 * DEFINISANJE TIPOVA U JAVASCRIPT
 * OVO SE ZOVE JS COMMEND DECLERATION
 * POMAZE DA FUNKCIJA ZNA DA JE TAJ TRAZENI TIP, DA BI IZBACIO PROPERTIS ZA TAJ TIP
 *
 * @param {Request} request
 * @param {Response} response
 */
router.get("/info", (request, response) => {
  //primer json-a
  //   const a = {
  //     key: "value",
  //   };
  //   console.log(a.["key"]);
  return response.json({
    message: "App info",
  });
});
router.post("/user/signup", (request, response) => {
  try {
    if (!request.body.username) {
      throw new Error("Internal server error");
    }

    const data = {
      username: request.body.username,
    };
    console.log(data);
    return response.status(200).json({
      status: true,
      message: "Successfully user signup",
      s,
    });
  } catch (error) {
    return response.status(500).json({
      error: {
        message: "Internal server faild",
      },
    });
  }
});
//prmenjivu exportujemo kao modul
module.exports = router;
