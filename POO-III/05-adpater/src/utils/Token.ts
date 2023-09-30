export default class Token {
    private _token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ0b2tlbiI6ImVudmlhbmRvIGUgcmVjZWJlbmRvIHBhZ2FtZW50b3MifQ.nzufIunnn-OUJhnlWap7VyoSOEu3Fd_q-XeZfhgqHS4";

    public get token() {
        return this._token;
    }
    public set token(value) {
        this._token = value;
    }
    
}