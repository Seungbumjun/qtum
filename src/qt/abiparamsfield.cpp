#include "abiparamsfield.h"
#include "abiparam.h"

#include "QStringList"

ABIParamsField::ABIParamsField(QWidget *parent) :
    QWidget(parent),
    m_mainLayout(new QVBoxLayout(this))
{
    m_mainLayout->setSpacing(6);
    m_mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(m_mainLayout);
}

void ABIParamsField::updateParamsField(const FunctionABI &function)
{
    // Add function parameters
    m_listParams.clear();
    int paramId = 0;
    for(std::vector<ParameterABI>::const_iterator param = function.inputs.begin(); param != function.inputs.end(); ++param)
    {
        ABIParam *paramFiled = new ABIParam(paramId, *param);
        m_listParams.append(paramFiled);
        m_mainLayout->addWidget(paramFiled);
        paramId++;
    }
}

QString ABIParamsField::getParamValue(int paramID)
{
    // Get parameter value
    return m_listParams[paramID]->getValue();
}

QStringList ABIParamsField::getParamsValues()
{
    // Get parameters values
    QStringList resultList;
    for(int i = 0; i < m_listParams.count(); ++i){
        resultList.append(m_listParams[i]->getValue());
    }
    return resultList;
}

bool ABIParamsField::isValid()
{
    bool isValid = true;
    for(int i = 0; i < m_listParams.count(); ++i){
        if(!m_listParams[i]->isValid())
            isValid = false;
    }
    return isValid;
}

