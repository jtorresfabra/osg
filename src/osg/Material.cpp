#include "osg/Material"
#include "osg/BoundsChecking"

using namespace osg;

Material::Material()
{
    _colorMode = OFF;

    _ambientFrontAndBack = true;
    _ambientFront.set(0.2f, 0.2f, 0.2f, 1.0f);
    _ambientBack.set(0.2f, 0.2f, 0.2f, 1.0f);

    _diffuseFrontAndBack = true;
    _diffuseFront.set(0.8f, 0.8f, 0.8f, 1.0f);
    _diffuseBack.set(0.8f, 0.8f, 0.8f, 1.0f);

    _specularFrontAndBack = true;
    _specularFront.set(0.0f, 0.0f, 0.0f, 1.0f);
    _specularBack.set(0.0f, 0.0f, 0.0f, 1.0f);

    _emissionFrontAndBack = true;
    _emissionFront.set(0.0f, 0.0f, 0.0f, 1.0f);
    _emissionBack.set(0.0f, 0.0f, 0.0f, 1.0f);

    _shininessFrontAndBack = true;
    _shininessFront = 0.0f;
    _shininessBack = 0.0f;
}


Material::~Material()
{
}


void Material::setAmbient( const Face face, const Vec4& ambient )
{
    switch(face)
    {
        case(FRONT):
            _ambientFrontAndBack = false;
            _ambientFront = ambient;
            clampArray4BetweenRange(_ambientFront,0.0f,1.0f,"osg::Material::setAmbient(..)");
            break;
        case(BACK):
            _ambientFrontAndBack = false;
            _ambientBack = ambient;
            clampArray4BetweenRange(_ambientBack,0.0f,1.0f,"Material::setAmbient(..)");
            break;
        case(FRONT_AND_BACK):
            _ambientFrontAndBack = true;
            _ambientFront = ambient;
            clampArray4BetweenRange(_ambientFront,0.0f,1.0f,"Material::setAmbient(..)");
            _ambientBack = _ambientFront;
            break;
        default:
            notify(NOTICE)<<"Notice: invalid Face passed to Material::setAmbient()."<<endl;
    }
}


const Vec4& Material::getAmbient(const Face face) const
{
    switch(face)
    {
        case(FRONT):
            return _ambientFront;
        case(BACK):
            return _ambientBack;
        case(FRONT_AND_BACK):
            if (!_ambientFrontAndBack)
            {
                notify(NOTICE)<<"Notice: Material::getAmbient(FRONT_AND_BACK) called on material "<<endl;
                notify(NOTICE)<<"        with seperate FRONT and BACK ambient colors."<<endl;
            }
            return _ambientFront;
    }
    notify(NOTICE)<<"Notice: invalid Face passed to Material::getAmbient()."<<endl;
    return _ambientFront;
}


void Material::setDiffuse( const Face face, const Vec4& diffuse )
{
    switch(face)
    {
        case(FRONT):
            _diffuseFrontAndBack = false;
            _diffuseFront = diffuse;
            clampArray4BetweenRange(_diffuseFront,0.0f,1.0f,"Material::setDiffuse(..)");
            break;
        case(BACK):
            _diffuseFrontAndBack = false;
            _diffuseBack = diffuse;
            clampArray4BetweenRange(_diffuseBack,0.0f,1.0f,"Material::setDiffuse(..)");
            break;
        case(FRONT_AND_BACK):
            _diffuseFrontAndBack = true;
            _diffuseFront = diffuse;
            clampArray4BetweenRange(_diffuseFront,0.0f,1.0f,"Material::setDiffuse(..)");
            _diffuseBack = _diffuseFront;
            break;
        default:
            notify(NOTICE)<<"Notice: invalid Face passed to Material::setDiffuse()."<<endl;
            break;
    }
}


const Vec4& Material::getDiffuse(const Face face) const
{
    switch(face)
    {
        case(FRONT):
            return _diffuseFront;
        case(BACK):
            return _diffuseBack;
        case(FRONT_AND_BACK):
            if (!_diffuseFrontAndBack)
            {
                notify(NOTICE)<<"Notice: Material::getDiffuse(FRONT_AND_BACK) called on material "<<endl;
                notify(NOTICE)<<"        with seperate FRONT and BACK diffuse colors."<<endl;
            }
            return _diffuseFront;
    }
    notify(NOTICE)<<"Notice: invalid Face passed to Material::getDiffuse()."<<endl;
    return _diffuseFront;
}


void Material::setSpecular( const Face face, const Vec4& specular )
{
    switch(face)
    {
        case(FRONT):
            _specularFrontAndBack = false;
            _specularFront = specular;
            clampArray4BetweenRange(_specularFront,0.0f,1.0f,"Material::setSpecular(..)");
            break;
        case(BACK):
            _specularFrontAndBack = false;
            _specularBack = specular;
            clampArray4BetweenRange(_specularBack,0.0f,1.0f,"Material::setSpecular(..)");
            break;
        case(FRONT_AND_BACK):
            _specularFrontAndBack = true;
            _specularFront = specular;
            clampArray4BetweenRange(_specularFront,0.0f,1.0f,"Material::setSpecular(..)");
            _specularBack = _specularFront;
            break;
        default:
            notify(NOTICE)<<"Notice: invalid Face passed to Material::setSpecular()."<<endl;
            break;
    }
}


const Vec4& Material::getSpecular(const Face face) const
{
    switch(face)
    {
        case(FRONT):
            return _specularFront;
        case(BACK):
            return _specularBack;
        case(FRONT_AND_BACK):
            if (!_specularFrontAndBack)
            {
                notify(NOTICE)<<"Notice: Material::getSpecular(FRONT_AND_BACK) called on material "<<endl;
                notify(NOTICE)<<"        with seperate FRONT and BACK specular colors."<<endl;
            }
            return _specularFront;
    }
    notify(NOTICE)<<"Notice: invalid Face passed to Material::getSpecular()."<<endl;
    return _specularFront;
}


void Material::setEmission( const Face face, const Vec4& emission )
{
    switch(face)
    {
        case(FRONT):
            _emissionFrontAndBack = false;
            _emissionFront = emission;
            clampArray4BetweenRange(_emissionFront,0.0f,1.0f,"Material::setEmission(..)");
            break;
        case(BACK):
            _emissionFrontAndBack = false;
            _emissionBack = emission;
            clampArray4BetweenRange(_emissionBack,0.0f,1.0f,"Material::setEmission(..)");
            break;
        case(FRONT_AND_BACK):
            _emissionFrontAndBack = true;
            _emissionFront = emission;
            clampArray4BetweenRange(_emissionFront,0.0f,1.0f,"Material::setEmission(..)");
            _emissionBack = _emissionFront;
            break;
        default:
            notify(NOTICE)<<"Notice: invalid Face passed to Material::setEmission()."<<endl;
            break;
    }
}


const Vec4& Material::getEmission(const Face face) const
{
    switch(face)
    {
        case(FRONT):
            return _emissionFront;
        case(BACK):
            return _emissionBack;
        case(FRONT_AND_BACK):
            if (!_emissionFrontAndBack)
            {
                notify(NOTICE)<<"Notice: Material::getEmission(FRONT_AND_BACK) called on material "<<endl;
                notify(NOTICE)<<"        with seperate FRONT and BACK emission colors."<<endl;
            }
            return _emissionFront;
    }
    notify(NOTICE)<<"Notice: invalid Face passed to Material::getEmission()."<<endl;
    return _emissionFront;
}


void Material::setShininess( const Face face, float shininess )
{
    clampBetweenRange(shininess,0.0f,1.0f,"Material::setShininess()");
    
    switch(face)
    {
        case(FRONT):
            _shininessFrontAndBack = false;
            _shininessFront = shininess;
            break;
        case(BACK):
            _shininessFrontAndBack = false;
            _shininessBack = shininess;
            break;
        case(FRONT_AND_BACK):
            _shininessFrontAndBack = true;
            _shininessFront = shininess;
            _shininessBack = shininess;
            break;
        default:
            notify(NOTICE)<<"Notice: invalid Face passed to Material::setShininess()."<<endl;
            break;
    }
}


const float Material::getShininess(const Face face) const
{
    switch(face)
    {
        case(FRONT):
            return _shininessFront;
        case(BACK):
            return _shininessBack;
        case(FRONT_AND_BACK):
            if (!_shininessFrontAndBack)
            {
                notify(NOTICE)<<"Notice: Material::getShininess(FRONT_AND_BACK) called on material "<<endl;
                notify(NOTICE)<<"        with seperate FRONT and BACK shininess colors."<<endl;
            }
            return _shininessFront;
    }
    notify(NOTICE)<<"Notice: invalid Face passed to Material::getShininess()."<<endl;
    return _shininessFront;
}

void Material::setTransparency(const Face face,float transparency)
{
   clampBetweenRange(transparency,0.0f,1.0f,"Material::setTransparency()");

   if (face==FRONT || face==FRONT_AND_BACK)
   {
        _ambientFront[3] = 1.0f-transparency;
        _diffuseFront[3] = 1.0f-transparency;
        _specularFront[3] = 1.0f-transparency;
        _emissionFront[3] = 1.0f-transparency;
    }

    if (face==BACK || face==FRONT_AND_BACK)
    {
        _ambientBack[3] = 1.0f-transparency;
        _diffuseBack[3] = 1.0f-transparency;
        _specularBack[3] = 1.0f-transparency;
        _emissionBack[3] = 1.0f-transparency;
    }
}        

void Material::setAlpha(const Face face,float alpha)
{
   clampBetweenRange(alpha,0.0f,1.0f,"Material::setAlpha()");

   if (face==FRONT || face==FRONT_AND_BACK)
   {
        _ambientFront[3] = alpha;
        _diffuseFront[3] = alpha;
        _specularFront[3] = alpha;
        _emissionFront[3] = alpha;
    }

    if (face==BACK || face==FRONT_AND_BACK)
    {
        _ambientBack[3] = alpha;
        _diffuseBack[3] = alpha;
        _specularBack[3] = alpha;
        _emissionBack[3] = alpha;
    }
}

void Material::apply(State&) const
{
    if (_colorMode==OFF)
    {
        glDisable(GL_COLOR_MATERIAL);
        glColor4fv(_diffuseFront.ptr());
    }
    else
    {
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK,(GLenum)_colorMode);
        switch(_colorMode)
        {
            case(AMBIENT): glColor4fv(_ambientFront.ptr()); break;
            case(DIFFUSE): glColor4fv(_diffuseFront.ptr()); break;
            case(SPECULAR): glColor4fv(_specularFront.ptr()); break;
            case(EMISSION): glColor4fv(_emissionFront.ptr()); break;
            case(AMBIENT_AND_DIFFUSE): glColor4fv(_diffuseFront.ptr()); break;
            case(OFF): break;
        }
    }

    if (_colorMode!=AMBIENT && _colorMode!=AMBIENT_AND_DIFFUSE)
    {
        if (_ambientFrontAndBack)
        {
            glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, _ambientFront.ptr() );
        }
        else
        {
            glMaterialfv( GL_FRONT, GL_AMBIENT, _ambientFront.ptr() );
            glMaterialfv( GL_BACK, GL_AMBIENT, _ambientBack.ptr() );
        }
    }

    if (_colorMode!=DIFFUSE && _colorMode!=AMBIENT_AND_DIFFUSE)
    {
        if (_diffuseFrontAndBack)
        {
            glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, _diffuseFront.ptr() );
        }
        else
        {
            glMaterialfv( GL_FRONT, GL_DIFFUSE, _diffuseFront.ptr() );
            glMaterialfv( GL_BACK, GL_DIFFUSE, _diffuseBack.ptr() );
        }
    }

    if (_colorMode!=SPECULAR)
    {
        if (_specularFrontAndBack)
        {
            glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, _specularFront.ptr() );
        }
        else
        {
            glMaterialfv( GL_FRONT, GL_SPECULAR, _specularFront.ptr() );
            glMaterialfv( GL_BACK, GL_SPECULAR, _specularBack.ptr() );
        }
    }

    if (_colorMode!=EMISSION)
    {
        if (_emissionFrontAndBack)
        {
            glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, _emissionFront.ptr() );
        }
        else
        {
            glMaterialfv( GL_FRONT, GL_EMISSION, _emissionFront.ptr() );
            glMaterialfv( GL_BACK, GL_EMISSION, _emissionBack.ptr() );
        }
    }

    if (_shininessFrontAndBack)
    {
        glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, _shininessFront* 128.0f );
    }
    else
    {
        glMaterialf( GL_FRONT, GL_SHININESS, _shininessFront* 128.0f );
        glMaterialf( GL_BACK, GL_SHININESS, _shininessBack* 128.0f );
    }

}
